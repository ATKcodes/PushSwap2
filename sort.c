/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:20:51 by amaso             #+#    #+#             */
/*   Updated: 2022/10/01 15:20:53 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//Once sorted the numbers, we know at which position they have to be at the end
//of the program, and we can start working directly with that.
void	assigning_a(t_push *push)
{
	int	i;
	int	d;

	i = -1;
	while (++i < push->a.size)
		push->c.array[i].pos = i;
	i = -1;
	while (++i < push->a.size)
	{
		d = -1;
		while (++d < push->a.size)
			if (push->a.array[i].n == push->c.array[d].n)
				push->a.array[i].pos = push->c.array[d].pos;
	}
}

void	swap_a(t_push *push, int i)
{
	t_elem	temp;

	temp = push->a.array[i];
	push->a.array[i] = push->a.array[i + 1];
	push->a.array[i + 1] = temp;
}

void	swap_b(t_push *push, int i)
{
	t_elem	temp;

	temp = push->b.array[i];
	push->b.array[i] = push->b.array[i + 1];
	push->b.array[i + 1] = temp;
}

void	swap_c(t_push *push, int i)
{
	int	temp;

	temp = push->c.array[i].n;
	push->c.array[i].n = push->c.array[i + 1].n;
	push->c.array[i + 1].n = temp;
}

void	sorting_c(t_push *push)
{
	int	i;
	int	d;

	i = -1;
	d = -1;
	while (++d < (push->a.size - 1))
	{
		i = -1;
		while (++i < push->a.size)
		{
			if (i + 1 < push->a.size && push->c.array[i].n > push->c.array[i + 1].n)
				swap_c(push, i);
		}
	}
}
