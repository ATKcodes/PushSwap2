/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:26:27 by amaso             #+#    #+#             */
/*   Updated: 2022/10/29 18:26:51 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_all(t_push *push)
{
	free (push->b.array);
	free (push->a.array);
	free (push->c.array);
}

void	free_matrix(t_push *push)
{
	int	i;

	i = -1;
	while (++i < push->a.size)
		free (push->lis[i]);
}