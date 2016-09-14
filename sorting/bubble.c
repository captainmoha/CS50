#include <stdio.h>

void swap(int* a, int* b);
void bubble_sort(int arr[], int len);


int main(void)
{
	int arr[9] = {5, 9, 2, 0, 1, 9, 6, 11, 9};
	bubble_sort(arr, 9);
	for (int i = 0; i < 9; i++)
		printf("%i ", arr[i]);
	printf("\n");
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int arr[], int len)
{	
	int swap_count = 1;

	while(swap_count)
	{	
		// when we make no swaps that means that the list is sorted
		swap_count = 0;

		for (int j = 0; j < len - 1; j++)
		{	
			
			//printf("next: %i   current: %i\n", arr[j+1], arr[j]);
			if (arr[j+1] < arr[j])
			{
				swap(arr + j, arr + j + 1);
				swap_count++;	
			}
		}

		// for optimaization: because we know that the last element must be the biggest by now
		len--;
	}
}
