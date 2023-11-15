#include <stdbool.h>

#ifndef ANALYZE_H
#define ANALYZE_H

#define RESULT_COUNT 5
#define ITERATION_COUNT 100
#define ARRAY_SCALING_FACTOR 2
#define KiB 1024


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
typdef void (*void_func)(void);

typedef struct{
	sort_function sort_func;
	int* a;
	int n;
}sort_parameters;

typedef struct{
	search_function search_func;
	int* a;
	int n;
	int v;
}search_parameters;

void benchmark(void_func algorithm, void* params, result_t *results, int n);

#endif