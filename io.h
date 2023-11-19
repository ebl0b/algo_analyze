#ifndef IO_H
#define IO_H

void message(char* s);
void print_menu(const char** options, int num_options);
void print_results(cmp_result_t *cmp_results_arr, complexity_t O);
int input_int();

#endif