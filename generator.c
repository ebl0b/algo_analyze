#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "generator.h"
#include "analyze.h"
#include <stdio.h>

static void swap(int *x, int *y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

static void balance_arr(int arr[], int start, int end, int swapi){
    if (start >= end) { return; }

    int mid = start + (end - start) / 2;
    swap(&arr[swapi], &arr[mid]);

    if (mid + 1 <= end) {
        balance_arr(arr, mid + 1, end, mid);
    }
    if (start <= mid - 1) {
        balance_arr(arr, start, mid - 1, mid - 1);
    }
}

int* get_space(int size, int op){
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

void gen_sortarr(void* gen_params, void* params, gen_op op, int scalar){
	gen_sort_t* gen_data = (gen_sort_t*)gen_params;
	sort_parameters* sort_params = (sort_parameters*)params;
	sort_params->size = gen_data->size << scalar;
	sort_params->arr = get_space(sort_params->size, op);
	gen_data->gen_arr(sort_params->arr, sort_params->size);
}
void gen_searcharr(void* gen_params, void* params, gen_op op, int scalar){
	gen_search_t* gen_data = (gen_search_t*)gen_params;
	search_parameters* search_params = (search_parameters*)params;
	search_params->size = gen_data->size  << scalar;
	search_params->arr = get_space(search_params->size, op);
	gen_data->gen_arr(search_params->arr, search_params->size);
	gen_data->gen_val(search_params->arr, &(search_params->val), search_params->size);
}

void gen_rand_arr(int* arr, int size){
	for(int i = 0; i < size; i++){arr[i] = get_rand(0, size);}
}
void gen_incr_arr(int* arr, int size){
	for(int i = 0; i < size; i++){arr[i] = i;}
}
void gen_decr_arr(int* arr, int size){
	for(int i = 0; i < size; i++){arr[i] = size-1-i;}
}
void gen_first_val(int arr[], int* val, int size){
	*val = arr[0];
}
void gen_mid_val(int arr[], int* val, int size){
	*val = arr[size/2];
}
void gen_rand_val(int arr[], int* val, int size){
	*val = arr[get_rand(0, size)];
}
void gen_last_val(int arr[], int* val, int size){
	*val = arr[size-1];
}
void gen_balanced_arr(int* arr, int size){
	gen_incr_arr(arr, size);
	balance_arr(arr, 0, size-1, size-1);
}

