/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:24:11 by amaso             #+#    #+#             */
/*   Updated: 2022/12/05 22:24:13 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	find_extremes(t_push *push)
{
	int	i;

	i = 0;
	push->a.max = push->a.array[i];
	push->a.min = push->a.array[i];
	while (++i < push->a.size)
	{
		if (push->a.array[i] > push->a.max)
			push->a.max = push->a.array[i];
		else if (push->a.array[i] < push->a.min)
			push->a.min = push->a.array[i];
	}
}

void	calc_b(t_push *push, int i)
{
	int	rrb;

	rrb = i - push->b.size;
	if (-rrb < i)
		push->calc.mov_b[i] = rrb;
	else
		push->calc.mov_b[i] = i;	
}

void	calc_a2(t_push *push, int i, int d)
{
	int rra;

	rra = d - push->a.size;
	if (-rra < d)
		push->calc.mov_a[i] = rra;
	else
		push->calc.mov_a[i] = d;
}

void	calc_a(t_push *push, int i)
{
	int	d;

	d = 0;
	if (push->b.array[i] > push->a.max)
	{
		while (push->a.array[d] != push->a.max)
			push->a.array[d++];
	}
	else if (push->a.array[i] < push->a.min)
	{
		while (push->a.array[d] != push->a.min)
			push->a.array[d++];
	}
	else
	{
		if (push->a.array[0] > push->b.array[i])
		{
			d++;
			while (push->a.array[push->a.size - d])
				d++;
		}
		else
		{
			push->a.array[0] > push->b.array[i];
		}
	}
	calc_a2(push, i, d);
}

void	calc_moves(t_push *push)
{
	int	i;

	i = -1;
	push->calc.mov_b = ft_calloc(push->b.size + 1, sizeof(int));
	push->calc.mov_a = ft_calloc(push->b.size + 1, sizeof(int));
	while (++i < push->pars.size)
	{
		find_extremes(push);
		calc_b(push, i);
		calc_a(push, i);

	}
}
