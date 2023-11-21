#ifdef _WIN32
	#include <windows.h>
#else
	#include <time.h>
#endif
#include "algorithm.h"
#include "generator.h"
#include "analyze.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static void timer(double *cpu_time, int op){
	#ifdef _WIN32
	static LARGE_INTEGER frequency;
	LARGE_INTEGER count;
	if(op==START){
		if (frequency.QuadPart == 0) {QueryPerformanceFrequency(&frequency);}
    	QueryPerformanceCounter(&count);
    	*cpu_time -= (((double)count.QuadPart / (double)frequency.QuadPart) * (double)BILLION);
	}else{
		QueryPerformanceCounter(&count);
		*cpu_time += (((double)count.QuadPart / (double)frequency.QuadPart) * (double)BILLION);
	}
	#else
	struct timespec count;
	if(op==START){
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &count);
		*cpu_time -= ((double)count.tv_sec * (double)BILLION + (double)count.tv_nsec);
	}else{
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &count);
		*cpu_time += ((double)count.tv_sec * (double)BILLION + (double)count.tv_nsec);
	}
	#endif
}

static void benchmark(void_func algorithm, void* params, gen_funcp generator, void* gen_params, result_t *results, int n)
{
	double cpu_time = 0;
	double avg_cpu_time = 0;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<ITERATION_COUNT; j++){
			generator(gen_params, params, REALLOC, i);
			timer(&cpu_time, START);
			algorithm(params);
			timer(&cpu_time, STOP);
			avg_cpu_time += GET_AVG_TIME(cpu_time, ITERATION_COUNT);
			cpu_time = 0;
		}
		results[i].time = avg_cpu_time;
		results[i].size = ((generic_params*)(params))->size;
		avg_cpu_time = 0;
	}
	free(*((int**)params));
}

void sort_analyze(void* gen_params, sort_function algo, result_t* results){
	sort_parameters sort_params;
	sort_params.sort_func = algo;
	gen_sortarr(gen_params, (void*)&sort_params, MALLOC, 0);
	benchmark(sort_wrapper, (void*)&sort_params, gen_sortarr, gen_params, results, RESULT_COUNT);
}
void search_analyze(void* gen_params, search_function algo, result_t* results){
	search_parameters search_params;
	search_params.search_func = algo;
	gen_searcharr(gen_params, (void*)&search_params, MALLOC, 0);
	benchmark(search_wrapper, (void*)&search_params, gen_searcharr, gen_params, results, RESULT_COUNT);
}

void cmp_results(result_t *results, double cmp_results[][COMPLEXITY_COUNT]){
	for(int i = 0; i<RESULT_COUNT; i++){
		cmp_results[i][PADDING1] = NAN;
		cmp_results[i][O_N3] = (double)((long double)results[i].time / pow((long double)results[i].size, 3));
		cmp_results[i][O_N2] = results[i].time / pow(results[i].size, 2);
		cmp_results[i][O_NLOGN] = results[i].time / (results[i].size * log2(results[i].size));
		cmp_results[i][O_N] = results[i].time / results[i].size;
		cmp_results[i][O_LOGN] = results[i].time / log2(results[i].size);
		cmp_results[i][O_1] = results[i].time;
		cmp_results[i][PADDING2] = NAN;
	}
}