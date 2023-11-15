#include "algorithm.h"
#include "analyze.h"
#include "io.h"
#include "ui.h"
#include <stdlib.h>

//private

static choice_t get_choice(){
	return input_int();
}

static void ui_menu(){
	const char* options[] = {
		"Show menu",					"Clear screen",					"Quit\n",
		"Bubble sort (Best case)",		"Bubble sort (Worst case)",		"Bubble sort (Average case)\n",
		"Insertion sort (Best case)",	"Insertion sort (Worst case)",	"Insertion sort (Average case)\n",
		"Quick sort (Best case)",		"Quick sort (Worst case)",		"Quick sort (Average case)\n",
		"Linear search (Best case)",	"Linear search (Worst case)",	"Linear search (Average case)\n",
		"Binary search (Best case)",	"Binary search (Worst case)",	"Binary search (Average case)\n"
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

static void ui_results(result_t *results){

}

static void ui_sort_analyze(int c, sort_function *algo, result_t* results){
	int *a = get_arr(c);
	sort_parameters sort_params = {algo, a, sizeof(a)/sizeof(int)};
	benchmark(sort_wrapper, (void*)&sort_params, results, RESULT_COUNT);
}
static void ui_search_analyze(int c, search_function *algo, result_t* results){
	int *a = get_arr(c);
	int v = get_val(c);
	search_parameters search_params = {algo, a, sizeof(a)/sizeof(int), v};
	benchmark(search_wrapper, (void*)&search_params, results, RESULT_COUNT);
}


//public
void ui_start(){
	result_t *results;
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
				ui_sort_analyze(BUBBLE_BEST, bubble_sort, results);
				ui_results(results);
				break;
			case BUBBLE_WORST:
				ui_sort_analyze(BUBBLE_WORST, bubble_sort, results);
				ui_results(results);
				break;
			case BUBBLE_AVG:
				ui_sort_analyze(BUBBLE_AVG, bubble_sort, results);
				ui_results(results);
				break;
			case INSERTION_BEST:
				ui_sort_analyze(INSERTION_BEST, insertion_sort, results);
				ui_results(results);
				break;
			case INSERTION_WORST:
				ui_sort_analyze(INSERTION_WORST, insertion_sort, results);
				ui_results(results);
				break;
			case INSERTION_AVG:
				ui_sort_analyze(INSERTION_AVG, insertion_sort, results);
				ui_results(results);
				break;
			case QUICK_BEST:
				ui_sort_analyze(QUICK_BEST, quick_sort, results);
				ui_results(results);
				break;
			case QUICK_WORST:
				ui_sort_analyze(QUICK_WORST, quick_sort, results);
				ui_results(results);
				break;
			case QUICK_AVG:
				ui_sort_analyze(QUICK_AVG, quick_sort, results);
				ui_results(results);
				break;
			case LINEAR_BEST:
				ui_search_analyze(LINEAR_BEST, linear_search, results);
				ui_results(results);
				break;
			case LINEAR_WORST:
				ui_search_analyze(LINEAR_WORST, linear_search, results);
				ui_results(results);
				break;
			case LINEAR_AVG:
				ui_search_analyze(LINEAR_AVG, linear_search, results);
				ui_results(results);
				break;
			case BINARY_BEST:
				ui_search_analyze(BINARY_BEST, binary_search, results);
				ui_results(results);
				break;
			case BINARY_WORST:
				ui_search_analyze(BINARY_WORST, binary_search, results);
				ui_results(results);
				break;
			case BINARY_AVG:
				ui_search_analyze(BINARY_AVG, binary_search, results);
				ui_results(results);
				break;
			default:
				message("Non-valid choice");
		}
	}
}