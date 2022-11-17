#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *ft_copy_array(int *array, int n)
{
	int *copied_array;
	int i;

	i = -1;
	copied_array = malloc (sizeof(int) * n);
	while (++i < n)
		copied_array[i] = array[i];
	return (copied_array);
}

int last_less_occurrence(int *stack, int head_index)
{
	int head;
	int	i;

	head = stack[head_index];
	i = head_index;
	while (--i > 0)
	{
		if (stack[i] < head)
			return (i);
	}
	return (0);
}

//last_less_occurrence = indice dell'ultimo numero minore stretto di head;
// n = numero elementi stack,
// lis_array = array indicizzato
// stack = stack con tutti i numeri
int	lis (int *stack, int *lis_array, int n)
{
	if (n == 0)
		return (0);
	int lis_val;
	int	head_index = n - 1;
	int	inclusivesubStack_size;
	int	exclusivesubStack_size;
	int	*lis_array_copy_1;
	int	*lis_array_copy_2;

	inclusivesubStack_size = n - 1;
	exclusivesubStack_size = last_less_occurrence(stack, head_index);
	lis_array_copy_1 = ft_copy_array(lis_array, n);
	lis_array_copy_2 = ft_copy_array(lis_array, n);

	int	lis_with = lis(stack, lis_array_copy_1, inclusivesubStack_size);
	int	lis_without = lis(stack, lis_array_copy_2, exclusivesubStack_size);

	int	*tmp = lis_array;
	if (1 + lis_with > lis_without)
	{
		lis_array = lis_array_copy_1;
		lis_val = lis_with;
	}
	else
	{
		lis_array = lis_array_copy_2;
		lis_val = lis_without;
	}
	return (lis_val);
}

int main (int argc, char *argv[])
{
	int	*stack;
	int	*lis_array;
	int	n;
	int	i;

	n = atoi(argv[1]);
	stack = (int *) malloc(n * sizeof(int));
	lis_array = (int *) calloc(n, sizeof(int));
	i = 0;
	while (i < n)
	{
		printf ("%d\n", i);
		stack[i] = atoi(argv[i + 2]);
		i++;
	}
	printf("lis len is: %d\n", lis(stack, lis_array, n));
	i = 0;
	while (lis_array[i])
	{
		printf("lis[%d] = %d\n", i, lis_array[i]);
		i++;
	}
}
