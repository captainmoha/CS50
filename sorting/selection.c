#include <stdio.h>
#include <cs50.h>

void selection_sort(int arr[], int len);
void swap(int* x, int* y);

int main(void)
{	

	int arr[9] = {5, 9, 2, 0, 1, 9, 6, 11, 9};
	selection_sort(arr, 9);
	for (int i = 0; i < 9; i++)
		printf("%i ", arr[i]);
	printf("\n");
}

void selection_sort(int arr[], int len)
{

	for (int i = 0; i < len; i++)
	{
		
		int min_index = i;
		for (int j = min_index; j < len; j++)
		{	
			// printf("j: %i, min_index: %i\n", j, min_index);
			if (arr[j] < arr[min_index])
			{	
				min_index = j;
			}
		}

		swap(arr + i, arr + min_index);
	}
}

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp; 
}

