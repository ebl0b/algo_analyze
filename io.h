#ifndef IO_H
#define IO_H

void message(char* s);
void print_menu(const char** options, int num_options);
void print_results(result_t *results);
int input_int();

#endif