#include "insertion.h"

#include <stdio.h>

/* sort array, which contains n items. */
void insertion(int array[], int n)
{
	int i, j, temp;

	for (i = 0; i < n; i++) {
		temp = array[i];
		for (j = i; j > 0 && array[j-1] > temp; j--) {
			/* j > 0 ensure we'll never arrive array[-1] */
			array[j] = array[j-1];
		}
		array[j] = temp; /* now array[j-1] is smaller that temp */
	}
}

/* print all the items in array */
void print_array(int array[], int n) 
{
	int i = 0;
	for (; i < n; i++) {
		printf("%d\t", array[i]);
	}
	printf("\n");
}


int main(void)
{
	int array[] = {9,8,7,6,5,4,4,3,2,2,1};
	int length = 11;
	print_array(array, length);
	insertion(array, length);
	print_array(array, length);
}
