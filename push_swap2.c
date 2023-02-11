/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:57:18 by amaso             #+#    #+#             */
/*   Updated: 2023/02/02 15:57:20 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	case3(t_push *push)
{
	if (push->a.array[0] == 1 && push->a.array[1] == 3)
	{
		sa(push);
		ra(push);
	}
	else if (push->a.array[0] == 2 && push->a.array[1] == 1)
		sa(push);
	else if (push->a.array[0] == 2 && push->a.array[1] == 3)
		rra(push);
	else if (push->a.array[0] == 3 && push->a.array[1] == 1)
		ra(push);
	else if (push->a.array[0] == 3 && push->a.array[1] == 2)
	{
		ra(push);
		sa(push);
	}
}

void	case3_5(t_push *push)
{
	if (push->a.array[0] == push->a.min
		&& push->a.array[1] == push->a.max)
	{
		sa(push);
		ra(push);
	}
	else if (push->a.array[0] != push->a.max
		&& push->a.array[1] == push->a.min)
		sa(push);
	else if (push->a.array[0] != push->a.min
		&& push->a.array[1] == push->a.max)
		rra(push);
	else if (push->a.array[0] == push->a.max
		&& push->a.array[1] == push->a.min)
		ra(push);
	else if (push->a.array[0] == push->a.max
		&& push->a.array[1] != push->a.min)
	{
		ra(push);
		sa(push);
	}
}

void	extremes_case5(t_push *push)
{
	if (push->a.max == 5 && push->a.min == 3)
	{
		if (push->b.array[0] == 1)
			sb(push);
		pa(push);
		pa(push);
		push->flag_5 = 1;
	}
	else if (push->a.max == 3 && push->a.min == 1)
	{
		if (push->b.array[0] == 4)
			sb(push);
		pa(push);
		pa(push);
		ra(push);
		ra(push);
		push->flag_5 = 1;
	}
}

void	case5(t_push *push)
{
	int	i;

	i = 0;
	pb(push);
	pb(push);
	find_extremes(push);
	case3_5(push);
	extremes_case5(push);
	if (push->flag_5 != 1)
	{
		calc_moves(push);
		free (push->calc.mov_a);
		free (push->calc.mov_b);
		find_extremes(push);
		while (push->a.array[i] != push->a.min)
			i++;
		if (i > (push->a.size / 2))
		{
			while (push->a.array[0] != push->a.min)
				rra(push);
		}
		else if (i != 0)
		{
			while (push->a.array[0] != push->a.min)
				ra(push);
		}
	}
}
