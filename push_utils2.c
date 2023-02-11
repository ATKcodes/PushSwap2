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
// void	print_stacks(t_push *push)
// {
// 	for (int i = 0; i < push->a.size; i++)
// 		printf("stack a[i] = %d\n", push->a.array[i]);
// 	printf("\n");
// 	for (int i = 0; i < push->b.size; i++)
// 		printf("stack b[i] = %d\n", push->b.array[i]);
// 	printf("\n\n");
// }
