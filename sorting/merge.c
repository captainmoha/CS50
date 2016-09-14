#include <stdio.h>
#include <stdlib.h>

void merge_sort(int arr[], int start, int end);
void merge(int arr[], int start1, int end1, int start2, int end2);

// to hold the merged arrays
int temp[9] = {0};

int main(void)
{
	int arr[9] = {5, 9, 2, 0, 1, 9, 6, 11, 9};
	merge_sort(arr, 0, 9-1);
	for (int i = 0; i < 9; i++)
		printf("%i, ", arr[i]);
	printf("\n");

}

void merge_sort(int arr[], int start, int end)
{
	if (end > start)
	{
		int middle = (start + end) / 2;

		// sort the left half of the array
		merge_sort(arr, start, middle);

		// sort the right half of the array
		merge_sort(arr, middle + 1, end);

		// merge them
		merge(arr, start, middle, middle + 1 , end);
	}
}

void merge(int arr[], int start1, int end1, int start2, int end2)
{	
	// where to start
	int index = start1;
	int len = end2 - start1 + 1;

	// while there are still elements in both left and right arrays
	while ((start1 <= end1) && (start2 <= end2))
	{	

		if (arr[start1] <= arr[start2])
		{
			temp[index] = arr[start1];
			start1++;
			index++;
		}
		else
		{
			temp[index] = arr[start2];
			start2++;
			index++;
		}
	}
	
	// if  there are elements in the left array only
	while (start1 <= end1)
	{
		temp[index] = arr[start1];
		start1++;
		index++;
	}

	// if there are elements in the right array only 
	while (start2 <= end2)
	{
		temp[index] = arr[start2];
		start2++;
		index++;
	}

	// copy the temp array to the original array
	for (int i = end2, j = 0; j <= len; i--, j++)
    {
        arr[i] = temp[i];
    }
}
