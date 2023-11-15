#include <time.h>
#include "algorithm.h"

static void timer(long *timer_state, int op){
	if(op==START){

	}
	else if(op==STOP){

	}
	else{return;}
}

void benchmark(void_func algorithm, void* params, result_t *results, int n)
{
	long curr_time = 0;
	timer(&timer_state, START);
	algorithm(params);
	timer(&timer_state, STOP);
}