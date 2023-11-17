#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "generator.h"
#include <stdio.h>

static void create_balanced(int start, int end, int* arr){
	if(start>end)return;
	if(start==end)
		arr[0] = start;
	else{
		int mid = (start+end)/2;
		create_balanced(start, mid, arr);
		create_balanced(mid+1, end, arr);
	}
}

void modify_ptr(void* params, analysis_data_t data){
	int **arr_ptr = (int**)params;
	*arr_ptr = data.arr;
}

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

analysis_data_t gen_bubins_best(int scalar, int op){
	analysis_data_t data;
	int size = BUBINS_SIZE << scalar;
	data.arr = gen(size, op);
	for(int i = 0; i<size; i++)
		data.arr[i] = i;
	data.size = size;
	data.val = UNDEFINED;
	return data;
}
analysis_data_t gen_bubins_worst(int scalar, int op){
	analysis_data_t data;
	int size = BUBINS_SIZE << scalar;
	data.arr = gen(size, op);
	for(int i = 0; i<size; i++)
		data.arr[i] = size-i-1;
	data.size = size;
	data.val = UNDEFINED;
	return data;
}
analysis_data_t gen_bubins_avg(int scalar, int op){
	analysis_data_t data;
	int size = BUBINS_SIZE << scalar;
	data.arr = gen(size, op);
	for(int i = 0; i<size; i++)
		data.arr[i] = get_rand(0, size);
	data.size = size;
	data.val = UNDEFINED;
	return data;
}

analysis_data_t gen_quick_best(int scalar, int op){
	analysis_data_t data;
	int size = QUICK_SIZE << scalar;
	data.arr = gen(size, op);
	create_balanced(0, size-1, data.arr);
	data.size = size;
	data.val = UNDEFINED;
	return data;
}
analysis_data_t gen_quick_worst(int scalar, int op){
	analysis_data_t data;
	int size = QUICK_SIZE << scalar;
	data.arr = gen(size, op);
	for(int i = 0; i<size; i++)
		data.arr[i] = size-i-1;
	data.size = size;
	data.val = UNDEFINED;
	return data;
}
analysis_data_t gen_quick_avg(int scalar, int op){
	analysis_data_t data;
	int size = QUICK_SIZE << scalar;
	data.arr = gen(size, op);
	for(int i = 0; i<size; i++)
		data.arr[i] = get_rand(0, size);
	data.size = size;
	data.val = UNDEFINED;
	return data;
}

analysis_data_t gen_lin_best(int scalar, int op){
	analysis_data_t data;
	int size = LIN_SIZE << scalar;
	data.arr = gen(size, op);
	for(int i = 0; i<size; i++)
		data.arr[i] = i;
	data.size = size;
	data.val = 0;
	return data;
}
analysis_data_t gen_lin_worst(int scalar, int op){
	analysis_data_t data;
	int size = LIN_SIZE << scalar;
	data.arr = gen(size, op);
	for(int i = 0; i<size; i++)
		data.arr[i] = i;
	data.size = size;
	data.val = size-1;
	return data;
}
analysis_data_t gen_lin_avg(int scalar, int op){
	analysis_data_t data;
	int size = LIN_SIZE << scalar;
	data.arr = gen(size, op);
	for(int i = 0; i<size; i++)
		data.arr[i] = get_rand(0, size);
	data.size = size;
	data.val = data.arr[get_rand(0, size)];
	return data;
}

analysis_data_t gen_bin_best(int scalar, int op){
	analysis_data_t data;
	int size = BIN_SIZE << scalar;
	data.arr = gen(size, op);
	for(int i = 0; i<size; i++)
		data.arr[i] = i;
	data.size = size;
	data.val = data.arr[size/2];
	return data;
}
analysis_data_t gen_bin_worst(int scalar, int op){
	analysis_data_t data;
	int size = LIN_SIZE << scalar;
	data.arr = gen(size, op);
	for(int i = 0; i<size; i++)
		data.arr[i] = i;
	data.size = size;
	data.val = size-1;
	return data;
}
analysis_data_t gen_bin_avg(int scalar, int op){
	analysis_data_t data;
	int size = LIN_SIZE << scalar;
	data.arr = gen(size, op);
	for(int i = 0; i<size; i++)
		data.arr[i] = i;
	data.size = size;
	data.val = data.arr[get_rand(0, size)];
	return data;
}

