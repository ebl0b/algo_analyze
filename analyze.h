#include <stdbool.h>
#include <stdlib.h>
#include "generator.h"

#ifndef ANALYZE_H
#define ANALYZE_H

#define RESULT_COUNT 6
#define ITERATION_COUNT 20
#define BILLION 1000000000LL

typedef enum{
	START,
	STOP,
}timer_op;

typedef struct{
	int size;
	double time;
}result_t;

typedef void (*sort_function)(int*, int);
typedef bool (*search_function)(int*, int, int);
typedef void (*void_func)(void*);

typedef struct{
	int* arr;
	int size;
	sort_function sort_func;
}sort_parameters;

typedef struct{
	int* arr;
	int size;
	int val;
	search_function search_func;
}search_parameters;

typedef struct{
	int* arr;
	int size;
}generic_params;

void sort_analyze(gen_funcp generator, sort_function algo, result_t* results);
void search_analyze(gen_funcp generator, search_function algo, result_t* results);
#define GET_AVG_TIME(x, y) x/((double)y)

#endif