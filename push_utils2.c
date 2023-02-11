/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:17:48 by amaso             #+#    #+#             */
/*   Updated: 2022/12/05 22:17:51 by amaso            ###   ########.fr       */
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

void	find_lis_loop(t_push *push, int i)
{
	int	n;

	n = -1;
	while (++n < push->a.size)
	{
		i = n;
		push->lis[n][0] = push->a.array[n];
		while (++i < push->a.size + n)
		{
			if (i < push->a.size)
			{
				if (push->a.array[i] > push->lis[n][alen(push->lis[n]) - 1])
					push->lis[n][alen(push->lis[n])] = push->a.array[i];
			}
			else
			{
				if (push->a.array[i - push->a.size]
					> push->lis[n][alen(push->lis[n]) - 1])
					push->lis[n][alen(push->lis[n])]
						= push->a.array[i - push->a.size];
			}
		}
	}
}
