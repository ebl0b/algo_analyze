#include <stdio.h>
#include "algorithm.h"

int main(){
	int a[6] = {7, 1, 2, 5, 3, 4};
	int n = 6;
	//bubble_sort(a, n);
	//insertion_sort(a, n);
	quick_sort(a, n);
	printf("%d\n", binary_search(a, n, 1));
	for(int j = 0; j<6; j++){
		printf("%d, ", a[j]);
	}
	return 0;
}