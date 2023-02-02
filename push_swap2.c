/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:57:18 by amaso             #+#    #+#             */
/*   Updated: 2023/02/02 15:57:20 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void case3(t_push *push)
{
	if (push->a.array[0] == 1 && push->a.array[1] == 3)
	{
		ra(push);
		sa(push);
	}
	else if (push->a.array[0] == 2 && push->a.array[1] == 1)
		sa(push);
	else if (push->a.array[0] == 2 && push->a.array[1] == 3)
		rra(push);
	else if (push->a.array[0] == 3 && push->a.array[1] == 1)
		ra(push);
	else if (push->a.array[0] == 3 && push->a.array[1] == 2)
	{
		ra(push);
		sa(push);
	}
}