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
//RISCRIVI STA CAGATA, PENSA AI VARI CASI. RAGIONA UN ELEMENTO ALLA VOLTA DELL' ARRAY dio stronzo
void	push_cycle(t_push *push)
{
	int	i;
	int	d;
	int	e;
	int	n;

	i = 0;
	push->calc.matrix[0][0] = push->a.array[0];
	while (++i < push->calc.maxsize)
	{
		push->calc.newnumb = push->a.array[i];
		//d = 0;
		// while (++d < push->calc.maxsize)
		// {
		// 	e = 0;
		// 	n = 0;
		// 	if (push->calc.matrix[i][d] > push->calc.matrix[i - 1][d - 1])
		// 	{
		// 		
		// 		while (++n < push->calc.currentmax)
		// 			push->calc.matrix[++push->calc.current_row][n]
		// 				= push->calc.matrix[push->calc.current_row - 1][n];
		// 		push->calc.matrix[push->calc.current_row][n]
		// 			= push->calc.matrix[i][d];
		// 	}
		// 	else
		// 	{
		// 		n = d;
		// 		while (n - ++e > 0)
		// 		{
		// 			while (push->calc.matrix[i][d]
		// 				< push->calc.matrix[i - e][n]
		// 				&& (e < d)
		// 		}
		// 	}
		// }
	}
}

void	push_swap(t_push *push)
{
	int	i;

	i = -1;
	push->calc.currentmax = 1;
	push->calc.current_row = 0;
	push->calc.matrix = malloc (sizeof (int *) * push->calc.maxsize);
	while (++i < push->calc.maxsize)
		push->calc.matrix[i] = ft_calloc (sizeof (int), push->calc.maxsize);
	i = -1;
	push->calc.result = ft_calloc (sizeof (int), push->calc.maxsize);
	push_cycle(push);
}
