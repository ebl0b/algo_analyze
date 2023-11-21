#ifndef IO_H
#define IO_H

void message(char* s);
void print_menu(const char** options, int num_options);
void print_results(double cmp_results_matrix[][COMPLEXITY_COUNT], result_t *results, complexity_t O);
int input_int();

#endif