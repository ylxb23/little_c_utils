#include "shell_sort.h"

void print_array(int array[], int n)
{
	int i = 0;
	for (; i < n; i++) 
		printf("%d\t", array[i]);

	printf("\n");
}

void shell_sort(int array[], int n)
{
	int i, j, increment, temp;

	for (increment = n/2; increment > 0; increment /= 2) {
		for (i = increment; i < n; i++) {
			temp = array[i];

			for (j = i; j >= increment; j -= increment) {
				if (temp < array[j - increment])
					array[j] = array[j - increment];
				else
					break;
			}
			array[j] = temp;
		}
	}
}

int main(void)
{
	int array[] = {10,9,8,7,6,5,4,3,2,1};
	int length = 10;

	print_array(array, length);
	shell_sort(array, length);
	print_array(array, length);
}
