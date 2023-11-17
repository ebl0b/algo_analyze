#ifndef GENERATOR_H
#define GENERATOR_H

#define BUBINS_SIZE (1 << 10)
#define QUICK_SIZE (1 << 11)
#define LIN_SIZE (1 << 14)
#define BIN_SIZE (1 << 16)
#define UNDEFINED 0

typedef enum{
	MALLOC,
	REALLOC
}gen_op;

typedef struct{
	int *arr;
	int size;
	int val;
}analysis_data_t;

typedef analysis_data_t (*gen_funcp)(int, int);

analysis_data_t gen_bubins_best(int scalar, int op);
analysis_data_t gen_bubins_worst(int scalar, int op);
analysis_data_t gen_bubins_avg(int scalar, int op);

analysis_data_t gen_quick_best(int scalar, int op);
analysis_data_t gen_quick_worst(int scalar, int op);
analysis_data_t gen_quick_avg(int scalar, int op);

analysis_data_t gen_lin_best(int scalar, int op);
analysis_data_t gen_lin_worst(int scalar, int op);
analysis_data_t gen_lin_avg(int scalar, int op);

analysis_data_t gen_bin_best(int scalar, int op);
analysis_data_t gen_bin_worst(int scalar, int op);
analysis_data_t gen_bin_avg(int scalar, int op);

void modify_ptr(void* params, analysis_data_t data);
int* gen(int size, int op);
int get_rand(int low, int high);
void init_rand(void);

#endif