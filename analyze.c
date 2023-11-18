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
		*cpu_time -= (count.tv_sec * BILLION + count.tv_nsec);
	}else{
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &count);
		*cpu_time += (count.tv_sec * BILLION + count.tv_nsec);
	}
	#endif
}

static void benchmark(void_func algorithm, void* params, gen_funcp generator, result_t *results, int n)
{
	double cpu_time = 0;
	double avg_cpu_time = 0;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<ITERATION_COUNT; j++){
			generator(i, REALLOC, params);
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

void sort_analyze(gen_funcp generator, sort_function algo, result_t* results){
	sort_parameters sort_params;
	sort_params.sort_func = algo;
	generator(0, MALLOC, (void*)&sort_params);
	benchmark(sort_wrapper, (void*)&sort_params, generator, results, RESULT_COUNT);
}
void search_analyze(gen_funcp generator, search_function algo, result_t* results){
	search_parameters search_params;
	search_params.search_func = algo;
	generator(0, MALLOC, (void*)&search_params);
	benchmark(search_wrapper, (void*)&search_params, generator, results, RESULT_COUNT);
}