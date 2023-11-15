#include <stdio.h>
#include <string.h>

//public
void message(char* s){
	printf("INFO> %s\n", s);
}

void print_menu(const char** options, int num_options){
	for(int i = 0; i<num_options; i++){
		printf("(%d) %s\n",i+1, options[i]);
	}
}

void print_results(result_t *results){
    
}

int input_int(){
	int num;
    char term;
    printf("INPUT> ");

    while(scanf("%d%c", &num, &term) != 2 || term != '\n') {
        while(getchar() != '\n'); // Clear the input buffer
        message("Invalid input");
        printf("INPUT> ");
    }
    return num-1;
}