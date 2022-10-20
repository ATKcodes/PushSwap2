/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:52:36 by amaso             #+#    #+#             */
/*   Updated: 2022/09/30 15:53:08 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		l1;
	int		l2;

	i = 0;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	str = (char *) malloc (sizeof(char) * (l1 + l2 + 1));
	while (i < l1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i <= (l1 + l2))
	{
		str[i] = s2[i - l1];
		i++;
	}
	free (s1);
	return (str);
}

char	**ft_countwords(char *s, char c, int i, int n)
{
	char	**matrix;

	matrix = NULL;
	while (i < ft_strlen(s))
	{
		if (s[i] != c)
		{
			while (s[i] != c && i < ft_strlen(s))
				i++;
			n++;
			i--;
		}
		i++;
	}
	matrix = (char **) malloc (sizeof(char *) * (n + 1));
	if (matrix == NULL)
		return (NULL);
	matrix[n] = NULL;
	return (matrix);
}

char	**matrixgen(char *s, char c, int i, char **matrix)
{
	int	n;
	int	len;

	len = 0;
	n = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c)
		{
			while (s[i + len] != c && i + len < ft_strlen(s))
				len++;
			matrix[n] = ft_substr(s, i, len);
			n++;
			i = i + len;
			len = 0;
			i--;
		}
		i++;
	}
	return (matrix);
}

char	**ft_split(char *s, char c)
{
	char	**matrix;
	int		i;
	int		n;

	if (!s)
		return (NULL);
	matrix = NULL;
	n = 0;
	i = 0;
	matrix = ft_countwords(s, c, i, n);
	if (matrix == NULL)
		return (NULL);
	return (matrixgen(s, c, i, matrix));
}
