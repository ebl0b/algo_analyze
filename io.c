#include <stdio.h>
#include <string.h>
#include "analyze.h"
#include "io.h"
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

void print_results(double cmp_results_matrix[][COMPLEXITY_COUNT], result_t* results, complexity_t O){
    const char* complexity_str[] = {"---", "O(n^3)", "O(n^2)", "O(n*log2(n))", "O(n)", "O(log2(n))", "O(1)", "---"};
    char padded_str_size[COLUMN_PADDING];
    char padded_str_T[COLUMN_PADDING];
    sprintf(padded_str_size, "%-16s", "Size");
    sprintf(padded_str_T, "%-16s", "T(ns)");
    puts("");
    puts("_________________________________________________________________________________________________");
    printf("| %s\t| %s\t| %-10s\t| %-10s\t| %-10s\t|\n",  padded_str_size, 
                                                        padded_str_T,
                                                        complexity_str[O-1], 
                                                        complexity_str[O], 
                                                        complexity_str[O+1]);
    puts("|_______________________|_______________________|_______________|_______________|_______________|");
    for(int i = 0; i<RESULT_COUNT; i++){
        printf("| %-16d\t| %-16.1lf\t| %-10.4e\t| %-10.4e\t| %-10.4e\t|\n",    results[i].size,        
                                                                                results[i].time, 
                                                                                cmp_results_matrix[i][O-1], 
                                                                                cmp_results_matrix[i][O], 
                                                                                cmp_results_matrix[i][O+1]);
    }
    puts("|_______________________|_______________________|_______________|_______________|_______________|\n");
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