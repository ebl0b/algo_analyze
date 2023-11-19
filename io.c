#include <stdio.h>
#include <string.h>
#include "analyze.h"
#include <math.h>

//public
void message(char* s){
	printf("INFO> %s\n", s);
}

void print_menu(const char** options, int num_options){
    puts("______________________________________________");
	for(int i = 0; i<num_options; i++){
		printf("| (%d)\t| %-35s|\n",i+1, options[i]);
	}
    puts("|_______|____________________________________|");
    puts("");
}

void print_results(cmp_result_t *cmp_results_arr, complexity_t O){
    const char* complexity_str[] = {"---", "O(n^3)", "O(n^2)", "O(n*log2(n))", "O(n)", "O(log2(n))", "O(1)", "---"};
    puts("");
    puts("______________________________________________________________________________________________");
    printf("| Size                \t| %-20s\t| %-20s\t| %-20s|\n",      complexity_str[O-1], 
                                                                        complexity_str[O], 
                                                                        complexity_str[O+1]);
    puts("|_______________________|_______________________|_______________________|_____________________|");
    for(int i = 0; i<RESULT_COUNT; i++){
        printf("| %-20d\t| %-20.2lf\t| %-20.2lf\t| %-20.2lf|\n",        cmp_results_arr[i].size, 
                                                                        cmp_results_arr[i].cmp[O-1], 
                                                                        cmp_results_arr[i].cmp[O], 
                                                                        cmp_results_arr[i].cmp[O+1]);
    }
    puts("|_______________________|_______________________|_______________________|_____________________|\n");
}

int input_int(){
	int num;
    char term;
    printf("INPUT> ");

    while(scanf("%d%c", &num, &term) != 2 || term != '\n') {
        while(getchar() != '\n');
        message("Invalid input");
        printf("INPUT> ");
    }
    return num-1;
}