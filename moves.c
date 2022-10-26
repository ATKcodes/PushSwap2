/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:36:40 by amaso             #+#    #+#             */
/*   Updated: 2022/10/20 11:36:43 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_push *push)
{
	if (push->a.size >= 2)
		swap_a(push, 0);
}

void	sb(t_push *push)
{
	if (push->b.size >= 2)
		swap_b(push, 0);
}

void	ss(t_push *push)
{
	if (push->a.size >= 2 && push->b.size >= 2)
	{
		swap_a(push, 0);
		swap_b(push, 0);
	}
}

void	pa(t_push *push)
{
	int		i;
	t_elem	temp;

	if (push->b.array)
	{
		push->swap.array = malloc (sizeof(t_elem) * --push->b.size);
		temp = push->b.array[0];
		i = -1;
		while (++i < push->b.size)
			push->swap.array[i] = push->b.array[i + 1];
		free (push->b.array);
		push->b.array = push->swap.array;
		if (push->swap.array)
			free(push->swap.array);
		push->swap.array = malloc (sizeof(t_elem) * ++push->a.size);
		push->swap.array[0] = temp;
		i = 0;
		while (++i < push->a.size)
			push->swap.array[i] = push->a.array[i - 1];
		free (push->a.array);
		push->a.array = push->swap.array;
		if (push->swap.array)
			free(push->swap.array);
	}
}

void	pb(t_push *push)
{
	int		i;
	t_elem	temp;

	if (push->a.array)
	{	
		push->swap.array = malloc (sizeof(t_elem) * --push->a.size);
		temp = push->a.array[0];
		i = -1;
		while (++i < push->a.size)
			push->swap.array[i] = push->a.array[i + 1];
		free (push->a.array);
		// printf("size = %d\n", push->a.size);
		push->a.array = push->swap.array;
		for (int d = 0; d < push->a.size; d++)
			printf("indice : %d, numero : %d\n", d, push->a.array[d].n);
		pb2(push, temp);
	}
	for (int d = 0; d < push->a.size; d++)
		printf("indice : %d, numero : %d\n", d, push->a.array[d].n);
}

void	pb2(t_push *push, t_elem temp)
{
	int		i;

	free(push->swap.array);
	for (int d = 0; d < push->a.size; d++)
		printf("indice : %d, numero : %d\n", d, push->a.array[d].n);
	push->swap.array = NULL;
	push->temp.array = malloc (sizeof(t_elem) * ++push->b.size);
	push->temp.array[0] = temp;
	for (int d = 0; d < push->a.size; d++)
		printf("indice : %d, numero : %d\n", d, push->a.array[d].n);
	i = 0;
	while (++i < push->b.size)
		push->temp.array[i] = push->b.array[i - 1];
	if (push->b.size > 1)
		free (push->b.array);
	push->b.array = push->temp.array;
	free (push->temp.array);
}
