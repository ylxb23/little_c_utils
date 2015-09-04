#ifndef MERGE_H
#define MERGE_H

/* we assume all the items has a `int` type. */
void merge_sort(int array[], int n);
void print_array(int array[], int n);
void msort(int array[], int tmp_array[], int left, int right);
void merge(int array[], int tmp_array[], int left, int right_start, int right_end);

#endif /* MERGE_H */
