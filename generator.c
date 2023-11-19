#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "generator.h"
#include "analyze.h"
#include <stdio.h>

int* gen(int size, int op){
	static int* arr = NULL;
	arr = op==MALLOC ? (int*)malloc(size * sizeof(int)) : (int*)realloc(arr, size * sizeof(int));
	return arr;
}

int get_rand(int low, int high){
	return (rand() % high)+low;
}

void init_rand(void){
	srand((unsigned)time(NULL));
}

void gen_bubins_best(int scalar, int op, void* params){
	sort_parameters* sort_params = (sort_parameters*)params;
	int size = BUBINS_SIZE << scalar;
	sort_params->arr = gen(size, op);
	for(int i = 0; i<size; i++)
		sort_params->arr[i] = i;
	sort_params->size = size;
}
void gen_bubins_worst(int scalar, int op, void* params){
	sort_parameters* sort_params = (sort_parameters*)params;
	int size = BUBINS_SIZE << scalar;
	sort_params->arr = gen(size, op);
	for(int i = 0; i<size; i++)
		sort_params->arr[i] = size-i-1;
	sort_params->size = size;
}
void gen_bubins_avg(int scalar, int op, void* params){
	sort_parameters* sort_params = (sort_parameters*)params;
	int size = BUBINS_SIZE << scalar;
	sort_params->arr = gen(size, op);
	for(int i = 0; i<size; i++)
		sort_params->arr[i] = get_rand(0, size);
	sort_params->size = size;
}

void gen_quick_best(int scalar, int op, void* params){
	sort_parameters* sort_params = (sort_parameters*)params;
	int size = QUICK_SIZE << scalar;
	sort_params->arr = gen(size, op);
	for(int i = 0; i<size; i++)
		sort_params->arr[i] = get_rand(0, size);
	sort_params->size = size;
}
void gen_quick_worst(int scalar, int op, void* params){
	sort_parameters* sort_params = (sort_parameters*)params;
	int size = QUICK_SIZE << scalar;
	sort_params->arr = gen(size, op);
	for(int i = 0; i<size; i++)
		sort_params->arr[i] = size-i-1;
	sort_params->size = size;
}
void gen_quick_avg(int scalar, int op, void* params){
	sort_parameters* sort_params = (sort_parameters*)params;
	int size = QUICK_SIZE << scalar;
	sort_params->arr = gen(size, op);
	for(int i = 0; i<size; i++)
		sort_params->arr[i] = get_rand(0, size);
	sort_params->size = size;
}

void gen_lin_best(int scalar, int op, void* params){
	search_parameters* search_params = (search_parameters*)params;
	int size = LIN_SIZE << scalar;
	search_params->arr = gen(size, op);
	for(int i = 0; i<size; i++)
		search_params->arr[i] = i;
	search_params->size = size;
	search_params->val = 0;
}
void gen_lin_worst(int scalar, int op, void* params){
	search_parameters* search_params = (search_parameters*)params;
	int size = LIN_SIZE << scalar;
	search_params->arr = gen(size, op);
	for(int i = 0; i<size; i++)
		search_params->arr[i] = i;
	search_params->size = size;
	search_params->val = size-1;
}
void gen_lin_avg(int scalar, int op, void* params){
	search_parameters* search_params = (search_parameters*)params;
	int size = LIN_SIZE << scalar;
	search_params->arr = gen(size, op);
	for(int i = 0; i<size; i++)
		search_params->arr[i] = get_rand(0, size);
	search_params->size = size;
	search_params->val = search_params->arr[get_rand(0, size)];
}

void gen_bin_best(int scalar, int op, void* params){
	search_parameters* search_params = (search_parameters*)params;
	int size = BIN_SIZE << scalar;
	search_params->arr = gen(size, op);
	for(int i = 0; i<size; i++)
		search_params->arr[i] = i;
	search_params->size = size;
	search_params->val = search_params->arr[size/2];
}
void gen_bin_worst(int scalar, int op, void* params){
	search_parameters* search_params = (search_parameters*)params;
	int size = BIN_SIZE << scalar;
	search_params->arr = gen(size, op);
	for(int i = 0; i<size; i++)
		search_params->arr[i] = i;
	search_params->size = size;
	search_params->val = size-1;
}
void gen_bin_avg(int scalar, int op, void* params){
	search_parameters* search_params = (search_parameters*)params;
	int size = BIN_SIZE << scalar;
	search_params->arr = gen(size, op);
	for(int i = 0; i<size; i++)
		search_params->arr[i] = i;
	search_params->size = size;
	search_params->val = search_params->arr[get_rand(0, size)];
}

