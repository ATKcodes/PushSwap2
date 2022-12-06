/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:58:55 by amaso             #+#    #+#             */
/*   Updated: 2022/10/20 11:58:57 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ra(t_push *push)
{
	int	i;
	int	temp;

	i = -1;
	temp = push->a.array[0];
	while (++i < (push->a.size - 1))
		push->a.array[i] = push->a.array[i + 1];
	push->a.array[i] = temp;
	ft_putstr("ra\n");
}

void	rb(t_push *push)
{
	int	i;
	int	temp;

	i = -1;
	temp = push->b.array[0];
	while (++i < (push->b.size - 1))
		push->b.array[i] = push->b.array[i + 1];
	push->b.array[i] = temp;
	ft_putstr("rb\n");
}

void	rr(t_push *push)
{
	int	i;
	int	temp;

	i = -1;
	temp = push->a.array[0];
	while (++i < (push->a.size - 1))
		push->a.array[i] = push->a.array[i + 1];
	push->a.array[i] = temp;
	i = -1;
	temp = push->b.array[0];
	while (++i < (push->b.size - 1))
		push->b.array[i] = push->b.array[i + 1];
	push->b.array[i] = temp;
	ft_putstr("rr\n");
}

void	pb(t_push *push)
{
	int	i;
	int	temp;

	if (push->a.size > 0)
	{
		i = -1;
		push->swap.array = malloc (sizeof(int) * --push->a.size);
		temp = push->a.array[0];
		while (++i < push->a.size)
			push->swap.array[i] = push->a.array[i + 1];
		free (push->a.array);
		i = -1;
		push->a.array = malloc (sizeof(int) * push->a.size);
		while (++i < push->a.size)
			push->a.array[i] = push->swap.array[i];
		free (push->swap.array);
		pb2(push, temp);
	}
}

void	pa(t_push *push)
{
	int	i;
	int	temp;

	if (push->b.size > 0)
	{
		i = -1;
		push->swap.array = malloc (sizeof(int) * --push->b.size);
		temp = push->b.array[0];
		while (++i < push->b.size)
			push->swap.array[i] = push->b.array[i + 1];
		free (push->b.array);
		i = -1;
		push->b.array = malloc (sizeof(int) * push->b.size);
		while (++i < push->b.size)
			push->b.array[i] = push->swap.array[i];
		free (push->swap.array);
		pa2(push, temp);
	}
}
