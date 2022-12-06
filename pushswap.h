/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:31:41 by amaso             #+#    #+#             */
/*   Updated: 2022/09/30 15:31:43 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_elem{
	int	n;
	int	pos;
}			t_elem;

typedef struct s_stack{
	int		*array;
	int		size;
	int		max;
	int		min;
}			t_stack;

typedef struct s_pars{
	int		pos;
	char	*input;
	char	**split;
	int		size;
	long	*array;
}			t_pars;

// best_move = lowest number of moves for the index being analyzed in that moment
// curr_best = lowest number of moves until nowl
// best_index = index of curr_best.
typedef struct s_calc{
	int		*mov_a;
	int		*mov_b;
	int		best_move;
	int		curr_best;
	int		best_index;
}			t_calc;

typedef struct s_push{
	t_stack	a;
	t_stack	b;
	t_stack	c;
	t_stack	swap;
	t_pars	pars;
	t_calc	calc;
	int		**lis;
	int		temp;
	int		*lis_final;
}			t_push;

void	find_best2(t_push *push, int i);
void	find_best(t_push *push, int i);
void	move4(t_push *push);
void	move3(t_push *push);
void	move2(t_push *push);
void	move(t_push *push);

void	calc_b(t_push *push, int i);
void	calc_a2(t_push *push, int i, int d);
void	calc_a(t_push *push, int i);
void	find_extremes(t_push *push);
void	calc_moves(t_push *push);

int		check_lis(t_push *push, int elem);
void	move_lis(t_push *push);
void	lis_search(t_push *push);
void	find_lis(t_push *push);
void	push_swap(t_push *push);

void	free_all(t_push *push);
void	free_matrix(t_push *push);

void	sa(t_push *push);
void	sb(t_push *push);
void	ss(t_push *push);
void	pa(t_push *push);
void	pb(t_push *push);

void	ra(t_push *push);
void	rb(t_push *push);
void	rr(t_push *push);
void	pa2(t_push *push, int temp);
void	pb2(t_push *push, int temp);

void	rra(t_push *push);
void	rrb(t_push *push);
void	rrr(t_push *push);

void	assigning_a(t_push *push);
void	swap_a(t_push *push, int i);
void	swap_b(t_push *push, int i);
void	swap_c(t_push *push, int i);
void	sorting_c(t_push *push);

void	ft_error(char *str);
void	not_int(t_push *push);

void	is_copy(t_push *push);
char	*dfltcase(char *s, int start, int len);
char	*ft_substr(char *s, int start, int len);
void	*ft_calloc(int nmeb, int size);
void	*ft_memset(void *s, int c, int n);

char	*ft_strjoin(char *s1, char *s2);
char	**ft_countwords(char *s, char c, int i, int n);
char	**matrixgen(char *s, char c, int i, char **matrix);
char	**ft_split(char *s, char c);

long	ft_atolong(char *str, t_push *push);
int		ft_strlen(char *str);
int		ft_putstr(char *str);
void	*ft_memset(void *s, int c, int n);
void	*ft_calloc(int nmeb, int size);

void	print_stacks(t_push *push);
int		alen(int *array);

#endif
