#include <stdio.h>
#include <stdlib.h>

int _lis(int arr[], int n, int* max_ref)
{
	if (n == 1)
		return 1;
	int res, max_ending_here = 1;

	for (int i = 1; i < n; i++) {
		res = _lis(arr, i, max_ref);
		if (arr[i - 1] < arr[n - 1]
			&& res + 1 > max_ending_here)
			max_ending_here = res + 1;
	}
	if (*max_ref < max_ending_here)
		*max_ref = max_ending_here;
	return max_ending_here;
}

int lis(int arr[], int n)
{
	int max = 1;

	_lis(arr, n, &max);

	return max;
}

int main()
{
	int arr[] = { 49, 15, 17, 44, 7, 22, 21, 43, 30, 8, 48, 25, 1, 24, 33, 3, 11, 14, 26, 45, 38, 23, 39, 31, 16, 41, 47, 37, 9, 36, 50, 18, 34, 13, 20, 29, 35, 4, 28, 27, 32, 10, 19, 40, 42, 5, 12, 2, 46, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Length of lis is %d", lis(arr, n));
	return 0;
}
