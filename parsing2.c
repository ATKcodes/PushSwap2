/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:25:24 by amaso             #+#    #+#             */
/*   Updated: 2022/09/30 19:25:31 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	is_copy(t_push *push)
{
	int	i;
	int	d;

	i = -1;
	while (++i < push->a.size)
	{
		d = -1;
		while (++d < i)
		{
			if (push->a.array[d] == push->a.array[i])
			{
				free (push->a.array);
				ft_error ("invalid input : arguments are not unique");
			}
		}
	}
}

char	*dfltcase(char *s, int start, int len)
{
	char	*sub;
	int		i;
	int		c;

	i = 0;
	c = (ft_strlen(s) - (int) start);
	if (ft_strlen(s) - start > len)
		sub = (char *) malloc((sizeof(char) * (len + 1)));
	else
		sub = (char *) malloc(sizeof(char) * ((ft_strlen(s) - start) + 1));
	if (sub == NULL)
		return (NULL);
	while (i < len && i < c)
	{
		sub[i] = s[(int) start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*sub;

	if (!s)
		return (0);
	if (ft_strlen(s) > (int) start)
		return (dfltcase(s, start, len));
	else
	{
		sub = malloc(sizeof(char) * 1);
		if (sub == NULL)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
}
