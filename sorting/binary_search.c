#include <stdio.h>

void sort(int arr[], int len);
short b_search(int start, int end, int target, int arr[]);
void swap(int* x, int* y);
void find(int arr[], int target, int len);

int main(void)
{
	int arr[9] = {5, 9, 2, 0, 1, 9, 6, 11, 9};
	sort(arr, 9);
	for (int i = 0; i < 9; i++)
		printf("%i ", arr[i]);
	printf("\n");

	int target = 0;
	printf("Enter the element you wanna look for\n");
	scanf("%i", &target);
	find(arr, target, 9);
}

void sort(int arr[], int len)
{
	int swapping = 1;

	while(swapping)
	{	
		swapping = 0;
		for (int i = 0; i < len; i++)
		{
			if (arr[i+1] < arr[i])
			{
				swap(arr+i+1, arr+i);
				swapping++;
			}
		}
		len--;
	}
}

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void find(int arr[], int target, int len)
{
	b_search(0, len - 1, target, arr);
}

short b_search(int start, int end, int target, int arr[])
{	
	if (start > end)
	{	
		printf("Element %i was not found.\n", target);
		return 0;
	}

	else
	{
		int mid = start + (end - start) / 2;

		if (target == arr[mid])
		{
			printf("Element %i was found at index %i.\n", target, mid);
			return 1;
		}

		else if (target > arr[mid])
		{
			b_search(mid+1, end, target, arr);
		}

		else if (target < arr[mid])
		{
			b_search(start, mid-1, target, arr);
		}
	}
	
}

