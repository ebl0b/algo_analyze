#include "algorithm.h"
#include <stdlib.h>

//
// Private
//
static void swap(int *x, int *y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

static int partion(int *a, int end){
	int pivoti = (end-1);
	int j = 0;
	for(int i = 0; i<end-1; i++){
		if(a[i] < a[pivoti]){
			swap(a+i, a+j);
			j++;
		}
	}
	swap(a+j, a+pivoti);
	return j;
}

//
// Public
//
void bubble_sort(int *a, int n)
{
	int sorted = 0;
	while(!sorted){
		sorted = 1;
		for(int i = 0; i<n-1; i++){
			if(a[i] > a[i+1]){		
				swap(a+i, a+(i+1));
				sorted = 0;
			}
		}
		n--;
	}
}

void insertion_sort(int *a, int n)
{
	for(int i = 1; i<n; i++){
		int j = i;
		while(j > 0 && a[j-1] > a[j]){
			swap(a+j, a+(j-1));
			j--;
		}
	}
}

void quick_sort(int *a, int n)
{
	if(n<=1) return;
	int pivoti = partion(a, n);
	quick_sort(a, pivoti);
	quick_sort(a+pivoti+1, n-pivoti-1);
}

bool linear_search(const int *a, int n, int v)
{
	for(int i = 0; i < n; i++){
		if(a[i]==v){
			return true;
		}
	} 
	return false;
}

bool binary_search(const int *a, int n, int v)
{
	int mid = n/2;
	return	n == 0 		? false	:
			a[mid]==v 	? true	: binary_search(v > a[mid] ? a+mid+1 : a, 
												v > a[mid] ? n-mid-1 : mid, 
												v);
}

void search_wrapper(void *params){
	search_parameters* search_params = (search_parameters*)params;
    bool found = search_params->search_func(search_params->a, search_params->n, search_params->v);
}

void sort_wrapper(void *params){
	sort_parameters* sort_params = (sort_parameters*)params;
    sort_params->sort_func(sort_params->a, sort_params->n);
}
