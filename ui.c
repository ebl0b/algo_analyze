#include "algorithm.h"
#include "analyze.h"
#include "io.h"
#include "ui.h"
#include "generator.h"
#include <stdlib.h>

//private

static choice_t get_choice(){
	return input_int();
}

static void ui_menu(){
	const char* options[] = {
		"Show menu",					"Clear screen",					"Quit",
		"Bubble sort (Best case)",		"Bubble sort (Worst case)",		"Bubble sort (Average case)",
		"Insertion sort (Best case)",	"Insertion sort (Worst case)",	"Insertion sort (Average case)",
		"Quick sort (Best case)",		"Quick sort (Worst case)",		"Quick sort (Average case)",
		"Linear search (Best case)",	"Linear search (Worst case)",	"Linear search (Average case)",
		"Binary search (Best case)",	"Binary search (Worst case)",	"Binary search (Average case)"
	};
	print_menu(options, sizeof(options)/sizeof(char*));
}
static void cls(){
	#ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

static void ui_results(result_t *results, complexity_t O){
	cmp_result_t cmp_results_arr[RESULT_COUNT];
	double tmp[RESULT_COUNT][COMPLEXITY_COUNT];
	for(int i = 0; i<RESULT_COUNT; i++)
		cmp_results_arr[i].cmp = tmp[i];
	cmp_results(results, cmp_results_arr);
	print_results(cmp_results_arr, O);
}

//public
void ui_start(){
	result_t results[RESULT_COUNT];
	bool running = true;
	cls();
	ui_menu();
	while(running){
		switch(get_choice()){
			case MENU:
				ui_menu();
				break;
			case CLS:
				cls();
				ui_menu();
				break;
			case QUIT:
				message("Quitting...");
				exit(0);
			case BUBBLE_BEST:
				{gen_sort_t gen_params = {SIZE_N, gen_incr_arr};
				sort_analyze((void*)&gen_params, bubble_sort, results);}
				ui_results(results, O_N);
				break;
			case BUBBLE_WORST:
				{gen_sort_t gen_params = {SIZE_N2, gen_decr_arr};
				sort_analyze((void*)&gen_params, bubble_sort, results);}
				ui_results(results, O_N2);
				break;
			case BUBBLE_AVG:
				{gen_sort_t gen_params = {SIZE_N2, gen_rand_arr};
				sort_analyze((void*)&gen_params, bubble_sort, results);}
				ui_results(results, O_N2);
				break;
			case INSERTION_BEST:
				{gen_sort_t gen_params = {SIZE_N, gen_incr_arr};
				sort_analyze((void*)&gen_params, insertion_sort, results);}
				ui_results(results, O_N);
				break;
			case INSERTION_WORST:
				{gen_sort_t gen_params = {SIZE_N2, gen_decr_arr};
				sort_analyze((void*)&gen_params, insertion_sort, results);}
				ui_results(results, O_N2);
				break;
			case INSERTION_AVG:
				{gen_sort_t gen_params = {SIZE_N2, gen_rand_arr};
				sort_analyze((void*)&gen_params, insertion_sort, results);}
				ui_results(results, O_N2);
				break;
			case QUICK_BEST:
				{gen_sort_t gen_params = {SIZE_NLOGN, gen_rand_arr};
				sort_analyze((void*)&gen_params, quick_sort, results);}
				ui_results(results, O_NLOGN);
				break;
			case QUICK_WORST:
				{gen_sort_t gen_params = {SIZE_N2, gen_decr_arr};
				sort_analyze((void*)&gen_params, quick_sort, results);}
				ui_results(results, O_N2);
				break;
			case QUICK_AVG:
				{gen_sort_t gen_params = {SIZE_NLOGN, gen_rand_arr};
				sort_analyze((void*)&gen_params, quick_sort, results);}
				ui_results(results, O_NLOGN);
				break;
			case LINEAR_BEST:
				{gen_search_t gen_params = {SIZE_1, gen_incr_arr, gen_first_val};
				search_analyze((void*)&gen_params, linear_search, results);}
				ui_results(results, O_1);
				break;
			case LINEAR_WORST:
				{gen_search_t gen_params = {SIZE_N, gen_incr_arr, gen_last_val};
				search_analyze((void*)&gen_params, linear_search, results);}
				ui_results(results, O_N);
				break;
			case LINEAR_AVG:
				{gen_search_t gen_params = {SIZE_N, gen_incr_arr, gen_rand_val};
				search_analyze((void*)&gen_params, linear_search, results);}
				ui_results(results, O_N);
				break;
			case BINARY_BEST:
				{gen_search_t gen_params = {SIZE_1, gen_incr_arr, gen_mid_val};
				search_analyze((void*)&gen_params, binary_search, results);}
				ui_results(results, O_1);
				break;
			case BINARY_WORST:
				{gen_search_t gen_params = {SIZE_LOGN, gen_incr_arr, gen_last_val};
				search_analyze((void*)&gen_params, binary_search, results);}
				ui_results(results, O_LOGN);
				break;
			case BINARY_AVG:
				{gen_search_t gen_params = {SIZE_LOGN, gen_incr_arr, gen_rand_val};
				search_analyze((void*)&gen_params, binary_search, results);}
				ui_results(results, O_LOGN);
				break;
			default:
				message("Non-valid choice");
		}
	}
}