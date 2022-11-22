#include <stdio.h>
#include <stdlib.h>

int rec_lis(int arr[], int n, int* max_ref)
{
	int res;
	int	max_ending_here;

	res = 1;
	max_ending_here = 1;
	if (n == 1)
		return 1;
	for (int i = 1; i < n; i++) {
		res = rec_lis(arr, i, max_ref);
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
	int max;

	max = 1;
	rec_lis(arr, n, &max);
	return (max);
}
int main()
{
	int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
	int n = sizeof(arr) / sizeof(int);
	printf("Length of lis is %d\n", lis(arr, n));
	return 0;
}
