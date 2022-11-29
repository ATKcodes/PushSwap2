/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:07:27 by amaso             #+#    #+#             */
/*   Updated: 2022/10/29 22:07:31 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	alen(int *array)
{
	int	i;

	i = 0;
	while (array[i] != 0)
		i++;
	return (i);
}

void	lis_search(t_push *push)
{
	int	max;
	int i;
	int max_i;

	max = 0;
	i = -1;
	while (++i < push->a.size)
	{
		if (alen(push->lis[i]) > max)
		{
			max = alen(push->lis[i]);
			max_i = i;
		}
	}
	i = -1;
	push->lis_final = ft_calloc (alen(push->lis[max_i]) + 1, sizeof(int));
	while (++i < alen(push->lis[max_i]))
		push->lis_final[i] = push->lis[max_i][i];
}

void	find_lis(t_push *push)
{
	int	i;
	int n;

	i = -1;
	push->lis = malloc (sizeof (int *) * push->a.size);
	while (++i < push->a.size)
		push->lis[i] = ft_calloc (sizeof(int), push->a.size + 1);
	n = -1;
	while (++n < push->a.size)
	{
		i = n;
		push->lis[n][0] = push->a.array[n];
		while (++i < push->a.size + n)
		{
			if (i < push->a.size)
			{
				if (push->a.array[i] > push->lis[n][alen(push->lis[n]) - 1])
					push->lis[n][alen(push->lis[n])] = push->a.array[i];
			}
			else
			{
				if (push->a.array[i - push->a.size] > push->lis[n][alen(push->lis[n]) - 1])
					push->lis[n][alen(push->lis[n])] = push->a.array[i - push->a.size];
			}
		}
	}
	lis_search(push);
}

void	push_swap(t_push *push)
{
	int	i;

	i = -1;
	find_lis(push);
	printf("lis len = %d\n", alen(push->lis_final));
	i = -1;
	while (++i < alen(push->lis_final))
		printf ("%d\n", push->lis_final[i]);
}
