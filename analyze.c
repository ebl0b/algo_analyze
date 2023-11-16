#ifdef _WIN32
	#include <windows.h>
#else
	#include <time.h>
#endif
#include "algorithm.h"
#include "generator.h"
#include <stdlib.h>

static void timer(long long *cpu_time, int op){
	#ifdef _WIN32
	static LARGE_INTEGER frequency;
	LARGE_INTEGER count;
	if(op==START){
		if (frequency.QuadPart == 0) {QueryPerformanceFrequency(&frequency);}
    	QueryPerformanceCounter(&count);
    	*cpu_time -= (count.QuadPart * BILLION / frequency.QuadPart);
	}else{
		QueryPerformanceCounter(&count);
		*cpu_time += (count.QuadPart * BILLION / frequency.QuadPart);
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

void sort_analyze(gen_funcp generator, sort_function algo, result_t* results){
	analysis_data_t data = generator(1);
	sort_parameters sort_params = {algo, data.arr, data.size};
	benchmark(sort_wrapper, (void*)&sort_params, results, RESULT_COUNT);
	free(data.arr);
}
void search_analyze(gen_funcp generator, search_function algo, result_t* results){
	analysis_data_t data = generator(1);
	search_parameters search_params = {algo, data.arr, data.size, data.val};
	benchmark(search_wrapper, (void*)&search_params, generator, results, RESULT_COUNT);
	free(data.arr);
}

static void benchmark(void_func algorithm, void* params, gen_funcp generator, result_t *results, int n)
{
	long long cpu_time = 0;
	double avg_cpu_time = 0;
	analysis_data_t tmp;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<ITERATION_COUNT; j++){
			timer(&cpu_time, START);
			algorithm(params);
			timer(&cpu_time, STOP);
			tmp = generator(i+1);
		}
		avg_cpu_time = GET_AVG_TIME(cpu_time, ITERATION_COUNT);
		results[i].time = avg_cpu_time;
		results[i].size = tmp.size;																	
		cpu_time = 0;
		avg_cpu_time = 0;
	}
}