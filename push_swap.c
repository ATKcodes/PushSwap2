/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:07:27 by amaso             #+#    #+#             */
/*   Updated: 2022/10/29 22:07:31 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	alen(int *array)
{
	int	i;

	i = 0;
	while (array[i] != 0)
		i++;
	return (i);
}

void	copy_earlier(t_push *push)
{
	int	i;

	i = -1;
	while (push->calc.matrix[push->calc.rcopy][++i] > 0)
	{
		push->calc.matrix[push->calc.rlast][i]
			= push->calc.matrix[push->calc.rcopy][i];
	}
	push->calc.cmax = push->calc.rlast;
}

// Next solution? > sul Jamboard : in breve > newnumb > 
// lastNumberarray[currentrow]? 
//se si Copia l'array attuale in un nuovo array e vai next,
//se no vai last Number array - ++n e riprova.
void	push_cycle(t_push *push)
{
	int	i;
	int	d;
	int	e;
	int	n;

	i = 0;
	push->calc.matrix[0][0] = push->a.array[0];
	while (++i < push->a.size)
	{
		push->calc.newnumb = push->a.array[i];
		if (push->calc.newnumb
			> push->calc.matrix[push->calc.cmax][push->calc.maxlen - 1])
		{
			push->calc.rlast++;
			push->calc.rcopy = push->calc.cmax;
			copy_earlier(push);
			push->calc.maxlen = alen(push->calc.matrix[push->calc.rlast]);
			push->calc.matrix[push->calc.rlast][++push->calc.maxlen]
				= push->calc.newnumb;
		}
		else
		{
			n = push->calc.rlast;
			while (--n > 0)
			{
				if (push->calc.matrix[n][alen(push->calc.matrix[n]) - 1]
					> push->calc.newnumb)
			}
		}
	}
}

void	push_swap(t_push *push)
{
	int	i;

	i = -1;
	push->calc.rlast = 0;
	push->calc.cmax = 0;
	push->calc.cmax = 0;
	push->calc.maxlen = 1;
	push->calc.matrix = malloc (sizeof (int *) * push->a.size);
	while (++i < push->a.size)
		push->calc.matrix[i] = ft_calloc (sizeof (int), push->a.size);
	i = -1;
	push->calc.result = ft_calloc (sizeof (int), push->a.size);
	push_cycle(push);
}
