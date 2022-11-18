/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 23:48:36 by amaso             #+#    #+#             */
/*   Updated: 2022/11/18 23:48:37 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int *ft_copy_array(int *array, int n)
{
	int *copied_array;
	int i;

	i = -1;
	copied_array = malloc (sizeof(int) * n);
	while (++i < n)
		copied_array[i] = array[i];
	return (copied_array);
}

void	lis(int stack, int len)
{
	int	*current_max;
	int	*current_lis;
	int	i;

	i = -1;
	while (++i < len)
	{
		current_lis = lis_rec(ft_copy_array(stack, i), i)
		if (array_length(current_lis) > array_length(current_max));
	}
}

int main ()
{
	int stack = [1, 2, 3, 4, 5];
	int len = 5;

	lis (stack, len);
	return (0);
}