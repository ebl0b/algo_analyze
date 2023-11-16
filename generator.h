#ifndef GENERATOR_H
#define GENERATOR_H

typedef enum{
	ITTER_BEST, ITTER_WORST, ITTER_AVG,
	REC_BEST, REC_WORST, REC_AVG, 
	LIN_BEST, LIN_WORST, LIN_AVG,
	BIN_BEST, BIN_WORST, BIN_AVG,
	NUMBER_OF_GENERATORS
}gen_key;

typedef struct{
	int *arr;
	int size;
	int val;
}analysis_data_t;

typedef analysis_data_t (*gen_funcp)(int);

analysis_data_t gen_itter_best(int scalar);
analysis_data_t gen_itter_worst(int scalar);
analysis_data_t gen_itter_avg(int scalar);

analysis_data_t gen_rec_best(int scalar);
analysis_data_t gen_rec_worst(int scalar);
analysis_data_t gen_rec_avg(int scalar);

analysis_data_t gen_lin_best(int scalar);
analysis_data_t gen_lin_worst(int scalar);
analysis_data_t gen_lin_avg(int scalar);

analysis_data_t gen_bin_best(int scalar);
analysis_data_t gen_bin_worst(int scalar);
analysis_data_t gen_bin_avg(int scalar);

#endif