#include <stdio.h>

void inserstion_sort(int arr[], int len);


int main(void)
{
	int arr[9] = {5, 9, 2, 0, 1, 9, 6, 11, 9};
	inserstion_sort(arr, 9);
	for (int i = 0; i < 9; i++)
		printf("%i ", arr[i]);
	printf("\n");
}

void inserstion_sort(int arr[], int len)
{
	
	for (int i = 1; i < len; i++)
	{
		int current = arr[i];
		int unsorted_index = i;  // where we are in the unsorted portion of the array

		// while the index > 0 and the previus element is greater
		while ((unsorted_index > 0) && (arr[unsorted_index - 1] > current))
		{	
			// shift big element to the right
			arr[unsorted_index] = arr[unsorted_index - 1];
			unsorted_index--;
		}
		arr[unsorted_index] = current;
	}
}