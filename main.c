/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:40:55 by amaso             #+#    #+#             */
/*   Updated: 2022/09/30 15:43:22 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	third_stack_sorting(t_push *push)
{
	int	i;

	i = -1;
	push->c.array = malloc (sizeof(int) * push->a.size);
	while (++i < push->a.size)
		push->c.array[i] = push->a.array[i];
	sorting_c(push);
	assigning_a(push);
}

void	stack_gen(t_push *push)
{
	int	i;

	i = -1;
	push->pars.size = 0;
	push->pars.split = NULL;
	push->pars.split = ft_split(push->pars.input, ' ');
	while (push->pars.split[++i])
		push->pars.size++;
	free (push->pars.input);
	push->pars.array = malloc (sizeof(long) * push->pars.size);
	i = -1;
	while (++i < push->pars.size)
		push->pars.array[i] = ft_atolong(push->pars.split[i], push);
	i = -1;
	while (++i < push->pars.size)
		free (push->pars.split[i]);
	free(push->pars.split);
	push->a.array = malloc (sizeof(push->a.array) * push->pars.size);
	push->a.size = push->pars.size;
	i = -1;
	while (++i < push->pars.size)
		push->a.array[i] = (int) push->pars.array[i];
	free (push->pars.array);
	is_copy(push);
}

void	check_input(t_push *push)
{
	int	i;

	i = -1;
	while (++i < ft_strlen(push->pars.input))
	{
		if (push->pars.input[i] == 45 || push->pars.input[i] == 43)
		{
			if (push->pars.input[i + 1] < 48 || push->pars.input[i + 1] > 57)
			{
				free (push->pars.input);
				ft_error("invalid input : no number after sign");
			}
		}
		else if ((push->pars.input[i] < 48 || push->pars.input[i] > 57)
			&& push->pars.input[i] != 32)
		{
			free (push->pars.input);
			ft_error("invalid input : invalid char");
		}
	}
}

//I'm adding a space after every argv to simplify the work for my split.
void	count_letters(int argc, char *argv[], t_push *push)
{
	int	i;

	i = 0;
	push->pars.input = malloc (1);
	push->pars.input[0] = '\0';
	while (++i < argc)
	{
		push->pars.input = ft_strjoin(push->pars.input, argv[i]);
		push->pars.input = ft_strjoin(push->pars.input, " ");
	}
}

int	main(int argc, char *argv[])
{
	t_push	push;

	count_letters(argc, argv, &push);
	check_input(&push);
	stack_gen(&push);
	third_stack_sorting(&push);
	push_swap(&push);
	print_stacks(&push);
	free_all(&push);
}
