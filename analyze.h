#include <stdbool.h>

#ifndef ANALYZE_H
#define ANALYZE_H

#define RESULT_COUNT 5
#define ITERATION_COUNT 100
#define ARRAY_SCALING_FACTOR 2
#define KiB 1024
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
typedef void (*void_func)(void);

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

void sort_analyze(int c, sort_function *algo, result_t* results);
void search_analyze(int c, search_function *algo, result_t* results);
#define GET_AVG_TIME(x, y) ((double)x)/((double)y)

#endif