#ifndef GENERATOR_H
#define GENERATOR_H

#define SIZE_N3 (1 << 3)
#define SIZE_N2 (1 << 7)
#define SIZE_NLOGN (1 << 15)
#define SIZE_N (1 << 19)
#define SIZE_LOGN (1 << 21)
#define SIZE_1 (1 << 21)

typedef enum{
	MALLOC,
	REALLOC
}gen_op;

typedef void (*gen_arr_funcp)(int*, int);
typedef void (*gen_val_funcp)(int*, int*, int);
typedef void (*gen_funcp)(void*, void*, gen_op, int);

typedef struct{
	int size;
	gen_arr_funcp gen_arr;
	gen_val_funcp gen_val;
}gen_search_t;

typedef struct{
	int size;
	gen_arr_funcp gen_arr;
}gen_sort_t;

void gen_sortarr(void* gen_params, void* params, gen_op op, int scalar);
void gen_searcharr(void* gen_params, void* params, gen_op op, int scalar);
void gen_rand_arr(int* arr, int size);
void gen_incr_arr(int* arr, int size);
void gen_decr_arr(int* arr, int size);
void gen_first_val(int arr[], int* val, int size);
void gen_mid_val(int arr[], int* val, int size);
void gen_rand_val(int arr[], int* val, int size);
void gen_last_val(int arr[], int* val, int size);
void gen_balanced_arr(int* arr, int size);

int* get_space(int size, int op);
int get_rand(int low, int high);
void init_rand(void);

#endif