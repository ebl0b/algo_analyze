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
	print_results(results);
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
				sort_analyze(gen_bubins_best, bubble_sort, results);
				ui_results(results);
				break;
			case BUBBLE_WORST:
				sort_analyze(gen_bubins_worst, bubble_sort, results);
				ui_results(results);
				break;
			case BUBBLE_AVG:
				sort_analyze(gen_bubins_avg, bubble_sort, results);
				ui_results(results);
				break;
			case INSERTION_BEST:
				sort_analyze(gen_bubins_best, insertion_sort, results);
				ui_results(results);
				break;
			case INSERTION_WORST:
				sort_analyze(gen_bubins_worst, insertion_sort, results);
				ui_results(results);
				break;
			case INSERTION_AVG:
				sort_analyze(gen_bubins_avg, insertion_sort, results);
				ui_results(results);
				break;
			case QUICK_BEST:
				sort_analyze(gen_quick_best, quick_sort, results);
				ui_results(results);
				break;
			case QUICK_WORST:
				sort_analyze(gen_quick_worst, quick_sort, results);
				ui_results(results);
				break;
			case QUICK_AVG:
				sort_analyze(gen_quick_avg, quick_sort, results);
				ui_results(results);
				break;
			case LINEAR_BEST:
				search_analyze(gen_lin_best, linear_search, results);
				ui_results(results);
				break;
			case LINEAR_WORST:
				search_analyze(gen_lin_worst, linear_search, results);
				ui_results(results);
				break;
			case LINEAR_AVG:
				search_analyze(gen_lin_avg, linear_search, results);
				ui_results(results);
				break;
			case BINARY_BEST:
				search_analyze(gen_bin_best, binary_search, results);
				ui_results(results);
				break;
			case BINARY_WORST:
				search_analyze(gen_bin_worst, binary_search, results);
				ui_results(results);
				break;
			case BINARY_AVG:
				search_analyze(gen_bin_avg, binary_search, results);
				ui_results(results);
				break;
			default:
				message("Non-valid choice");
		}
	}
}