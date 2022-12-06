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

void	find_best(t_push *push, int i)
{
	if (push->calc.mov_a[i] >= 0 && push->calc.mov_b[i] > 0)
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
}
