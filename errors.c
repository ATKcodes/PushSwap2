/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:01:45 by amaso             #+#    #+#             */
/*   Updated: 2022/10/01 13:01:47 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_error(char *str)
{
	ft_putstr(str);
	exit(1);
}

void	not_int(t_push *push)
{
	int	i;

	i = -1;
	if (push->pars.array)
		free(push->pars.array);
	while (++i < push->pars.size)
		free(push->pars.split[i]);
	free(push->pars.split);
	ft_error("Error : one of the arguments is not an int.");
}
