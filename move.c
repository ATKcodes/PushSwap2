/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:44:57 by amaso             #+#    #+#             */
/*   Updated: 2022/12/06 18:45:05 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	order_lis(t_push *push)
{
	int	i;

	find_extremes(push);
	i = 0;
	while (push->a.array[i] != push->a.min)
		i++;
	if (i > (push->a.size / 2))
		while (push->a.array[0] != push->a.min)
			rra(push);
	else
		while (push->a.array[0] != push->a.min)
			ra(push);
}

void	find_best2(t_push *push, int i)
{
	if (push->calc.best_move < push->calc.curr_best)
	{
		push->calc.curr_best = push->calc.best_move;
		push->calc.best_index = i;
	}
}

void	find_best(t_push *push, int i)
{
	if (push->calc.mov_a[i] >= 0 && push->calc.mov_b[i] >= 0)
	{
		if (push->calc.mov_a[i] > push->calc.mov_b[i])
			push->calc.best_move = push->calc.mov_a[i];
		else
			push->calc.best_move = push->calc.mov_b[i];
	}
	else if (push->calc.mov_a[i] >= 0 && push->calc.mov_b[i] < 0)
	{
		push->calc.best_move = (-1 * push->calc.mov_b[i]) + push->calc.mov_a[i];
	}
	else if (push->calc.mov_a[i] < 0 && push->calc.mov_b[i] >= 0)
	{
		push->calc.best_move = (-1 * push->calc.mov_a[i]) + push->calc.mov_b[i];	
	}
	else
	{
		if (push->calc.mov_a[i] > push->calc.mov_b[i])
			push->calc.best_move = (-1 * push->calc.mov_b[i]);
		else
			push->calc.best_move = (-1 * push->calc.mov_a[i]);
	}
	find_best2(push, i);
}

void	move4(t_push *push)
{
	if (push->calc.mov_a[push->calc.best_index] <= 0
		&& push->calc.mov_b[push->calc.best_index] <= 0
		&& push->calc.moveflag != 1)
	{
		while (push->calc.mov_a[push->calc.best_index] < 0 && push->calc.mov_b[push->calc.best_index] < 0)
		{
			push->calc.mov_a[push->calc.best_index] += 1;
			push->calc.mov_b[push->calc.best_index] += 1;
			rrr(push);
		}
		while (push->calc.mov_a[push->calc.best_index] < 0)
		{
			push->calc.mov_a[push->calc.best_index] += 1;
			rra(push);
		}
		while (push->calc.mov_b[push->calc.best_index] < 0)
		{
			push->calc.mov_b[push->calc.best_index] += 1;
			rrb(push);
		}
		push->calc.moveflag = 1;
		pa(push);
	}
}

void	move3(t_push *push)
{
	if (push->calc.mov_a[push->calc.best_index] <= 0
		&& push->calc.mov_b[push->calc.best_index] >= 0
		&& push->calc.moveflag != 1)
	{
		while (push->calc.mov_a[push->calc.best_index] < 0)
		{
			push->calc.mov_a[push->calc.best_index] += 1;
			rra(push);
		}
		while (push->calc.mov_b[push->calc.best_index] > 0)
		{
			push->calc.mov_b[push->calc.best_index] -= 1;
			rb(push);
		}
		push->calc.moveflag = 1;
		pa(push);
	}
	move4(push);
}

void	move2(t_push *push)
{
	if (push->calc.mov_a[push->calc.best_index] >= 0
		&& push->calc.mov_b[push->calc.best_index] <= 0
		&& push->calc.moveflag != 1)
	{
		while (push->calc.mov_a[push->calc.best_index] > 0)
		{
			push->calc.mov_a[push->calc.best_index] -= 1;
			ra(push);
		}
		while (push->calc.mov_b[push->calc.best_index] < 0)
		{
			push->calc.mov_b[push->calc.best_index] += 1;
			rrb(push);
		}
		push->calc.moveflag = 1;
		pa(push);
	}
	move3(push);
}

void	move(t_push *push)
{
	if (push->calc.mov_a[push->calc.best_index] >= 0
		&& push->calc.mov_b[push->calc.best_index] >= 0)
	{
		while (push->calc.mov_a[push->calc.best_index] > 0 && push->calc.mov_b[push->calc.best_index] > 0)
		{
			push->calc.mov_a[push->calc.best_index] -= 1;
			push->calc.mov_b[push->calc.best_index] -= 1;
			rr(push);
		}
		while (push->calc.mov_a[push->calc.best_index] > 0)
		{
			push->calc.mov_a[push->calc.best_index] -= 1;
			ra(push);
		}
		while (push->calc.mov_b[push->calc.best_index] > 0)
		{
			push->calc.mov_b[push->calc.best_index] -= 1;
			rb(push);
		}
		push->calc.moveflag = 1;
		pa(push);
	}
	move2(push);
}