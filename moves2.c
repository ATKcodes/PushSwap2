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
	int		i;
	t_elem	temp;

	i = -1;
	temp = push->a.array[0];
	while (++i < (push->a.size - 1))
		push->a.array[i] = push->a.array[i + 1];
	push->a.array[i] = temp;
}

void	rb(t_push *push)
{
	int		i;
	t_elem	temp;

	i = -1;
	temp = push->b.array[0];
	while (++i < (push->b.size - 1))
		push->b.array[i] = push->b.array[i + 1];
	push->b.array[i] = temp;
}

void	rr(t_push *push)
{
	int		i;
	t_elem	temp;

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
}