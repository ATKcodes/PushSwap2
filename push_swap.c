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

// 1 = is in the lis, 0 = is not in the lis.
int	check_lis(t_push *push, int elem)
{
	int	i;

	i = -1;
	while (++i < alen(push->lis_final))
	{
		if (elem == push->lis_final[i])
			return (1);
	}
	return (0);
}

void	move_lis(t_push *push)
{
	int	i;
	int	n;
	int tot;

	i = -1;
	n = 0;
	tot = push->a.size;
	printf("lis len = %d\n", alen(push->lis_final));
	i = -1;
	while (++i < alen(push->lis_final))
		printf ("%d\n", push->lis_final[i]);
	i = -1;
	while (++i < tot)
	{
		if (check_lis(push, push->a.array[0]) == 1)
			ra(push);
		else
		{
			pb(push);
			n++;
		}
	}
	print_stacks(push);
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
	if (alen(push->lis_final) == push->a.size && push->a.array[0] == 1)
	{
		free_all(push);
		exit (0);
	}
	move_lis(push);
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
}

void	push_swap(t_push *push)
{
	int	i;

	i = -1;
	find_lis(push);
	lis_search(push);
	free_matrix(push);
	order_lis(push);
	calc_moves(push);
}
