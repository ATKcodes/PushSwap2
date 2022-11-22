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

void	ft_array_changer(int *to_copy, int **res, int copy_len)
{
	int	i;

	i = -1;
	free (*res);
	*res = ft_calloc (sizeof(int), (copy_len + 1)); 
	while (++i < copy_len)
		*res[i] = to_copy[i];
}

int	*ft_copy_array(int *array, int n)
{
	int *copied_array;
	int i;

	i = -1;
	copied_array = malloc (sizeof(int) * n);
	while (++i < n)
		copied_array[i] = array[i];
	return (copied_array);
}

void	unshift(int **cur_lis, int n, int cur_lis_size)
{
	int	*array;
	int	i;

	array = ft_calloc (sizeof(int), cur_lis_size);
	array[0] = n;
	i = -1;
	while (++i < cur_lis_size)
		array[i + 1] = *cur_lis[i];
	free (*cur_lis);
	*cur_lis = ft_calloc (sizeof(int), cur_lis_size);
	i = -1;
	while (++i < cur_lis_size)
		*cur_lis[i] = array[i];
	free (array);
}

int	*lis_rec(int *stack, int s_len, int *cur_lis, t_push *push)
{
	int *with;
	int	*without;
	int	*new_cur_lis;

	if (s_len == 0)
		return (cur_lis);
	if (stack[s_len -1] > cur_lis[0])
		return (lis_rec(ft_copy_array(stack, s_len - 1), s_len - 1, cur_lis, push));
	with = ft_calloc (sizeof(int), push->a.size + 1);
	without = ft_calloc (sizeof(int), push->a.size + 1);
	new_cur_lis = ft_calloc (sizeof(int), push->a.size + 1);
	ft_array_changer(cur_lis, &new_cur_lis, push->a.size);
	unshift(&cur_lis, stack[s_len - 1], push->a.size + 1);
	ft_array_changer(lis_rec(ft_copy_array(stack, s_len - 1), s_len - 1, new_cur_lis, push), &with, push->a.size);
	ft_array_changer(lis_rec(ft_copy_array(stack, s_len - 1), s_len - 1, cur_lis ,push), &without, push->a.size);
	if (alen(without) > alen(with))
	{
		free (with);
		return (without);
	}
	else
	{
		free (without);
		return (with);
	}
}

void	find_lis(t_push *push)
{
	int	i;
	int	*current_lis;
	int	*current_max;
	int	*array;
	int	*rec;

	current_max = ft_calloc (sizeof(int), 1);
	array = ft_calloc (sizeof(int), 1);
	current_lis = ft_calloc (sizeof(int), 1);
	i = -1;
	while (++i < push->a.size)
	{
		free(array);
		array = ft_calloc (sizeof(int), push->a.size + 1);
		array[0] = push->a.array[i];
		ft_array_changer(lis_rec(push->a.array, i, array, push), &current_lis, push->a.size);
		if (alen(current_lis) > alen(current_max))
			ft_array_changer(current_lis, &current_max, push->a.size);
	}
	push->lis = malloc (sizeof(int) * 1);
	ft_array_changer(current_max, &push->lis, alen(current_max));
}

void	push_swap(t_push *push)
{
	int	i;

	i = -1;
	find_lis(push);
	printf ("lis len : %d\n", alen(push->lis));
	while (++i < alen(push->lis))
		printf("lis [%d] = %d\n", i, push->lis[i]);
}
