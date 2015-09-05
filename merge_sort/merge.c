#include <stdio.h>
#include <stdlib.h>

#include "merge.h"

void print_array(int array[], int length)
{
	int i;
	while (i < length)
		printf("%d -> ", array[i++]);
	printf("\n");
}

/* end is the length, but not the last index */
void msort(int array[], int tmp_array[], int start, int end)
{
	if (start < end - 1) {
		int center = (start + end) / 2;
		msort(array, tmp_array, start, center);
		msort(array, tmp_array, center, end);
		merge(array, tmp_array, start, center, end);
	}
}

/* [start, center), [center, end), both center and end is the length, but not 
 * the last index in that part.
 */
void merge(int array[], int tmp_array[], int start, int center, int end)
{
	int lt = start;
	int rt = center;
	int kt = start;

	while (lt < center && rt < end)
		tmp_array[kt++] = array[lt] < array[rt] ? array[lt++] : array[rt++];

	while (lt < center)
		tmp_array[kt++] = array[lt++];
	while (rt < end)
		tmp_array[kt++] = array[rt++];

	/* copy back tmp_array to array */
	for (kt = start; kt < end; kt++)
		array[kt] = tmp_array[kt];
}

void merge_sort(int array[], int length)
{
	int *tmp_array = malloc(sizeof(int) * length);
	if (tmp_array != NULL) {
		msort(array, tmp_array, 0, length);
		free(tmp_array);
	} else {
		printf("allocate memory failed! quit...");
		exit(-1);
	}
}

int main(void)
{
	int array[] = {5,4,3,2,1,6,8,3,9,10};
	int length = sizeof(array) / sizeof(int);

	print_array(array, length);
	merge_sort(array, length);
	print_array(array, length);
}
