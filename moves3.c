/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:42:24 by amaso             #+#    #+#             */
/*   Updated: 2022/10/20 12:42:41 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rra(t_push *push)
{
	int		i;
	t_elem	temp;

	i = push->a.size;
	temp = push->a.array[i];
	while (--i > 0)
		push->a.array[i] = push->a.array[i - 1];
}

void	rrb(t_push *push)
{
	int		i;
	t_elem	temp;

	i = push->b.size;
	temp = push->b.array[i];
	while (--i > 0)
		push->b.array[i] = push->b.array[i - 1];
}

void	rrr(t_push *push)
{
	int		i;
	t_elem	temp;

	i = push->a.size;
	temp = push->a.array[i];
	while (--i > 0)
		push->a.array[i] = push->a.array[i - 1];
	i = push->b.size;
	temp = push->b.array[i];
	while (--i > 0)
		push->b.array[i] = push->b.array[i - 1];
}
