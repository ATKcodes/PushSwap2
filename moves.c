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
	{
		swap_a(push, 0);
		ft_putstr("sa\n");
	}
}

void	sb(t_push *push)
{
	if (push->b.size >= 2)
	{
		swap_b(push, 0);
		ft_putstr("sb\n");
	}
}

void	ss(t_push *push)
{
	if (push->a.size >= 2 && push->b.size >= 2)
	{
		swap_a(push, 0);
		swap_b(push, 0);
		ft_putstr("ss\n");
	}
}

void	pa2(t_push *push, int temp)
{
	int	i;

	i = 0;
	push->swap.array = malloc (sizeof(int) * ++push->a.size);
	push->swap.array[i] = temp;
	while (++i < push->a.size)
		push->swap.array[i] = push->a.array[i - 1];
	free (push->a.array);
	i = -1;
	push->a.array = malloc (sizeof(int) * push->a.size);
	while (++i < push->a.size)
		push->a.array[i] = push->swap.array[i];
	free (push->swap.array);
	ft_putstr("pa\n");
}

void	pb2(t_push *push, int temp)
{
	int	i;

	i = 0;
	push->swap.array = malloc (sizeof(int) * ++push->b.size);
	push->swap.array[i] = temp;
	while (++i < push->b.size)
		push->swap.array[i] = push->b.array[i - 1];
	free (push->b.array);
	i = -1;
	push->b.array = malloc (sizeof(int) * push->b.size);
	while (++i < push->b.size)
		push->b.array[i] = push->swap.array[i];
	free (push->swap.array);
	ft_putstr("pb\n");
}
