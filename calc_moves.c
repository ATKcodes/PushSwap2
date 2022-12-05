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

void	calc_moves(t_push *push)
{
	int	i;

	i = -1;
	while (++i < push->pars.size)
	{
		find_extremes(push);
	}
}
