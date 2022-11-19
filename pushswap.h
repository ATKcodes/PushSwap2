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
}			t_stack;

typedef struct s_pars{
	int		pos;
	char	*input;
	char	**split;
	int		size;
	long	*array;
}			t_pars;

typedef struct s_push{
	t_stack	a;
	t_stack	b;
	t_stack	c;
	t_stack	swap;
	t_pars	pars;
	int		*lis;
	int		temp;
}			t_push;

void	push_swap(t_push *push);
int		alen(int *array);
int		*ft_copy_array(int *array, int n);
int		*unshift(int *cur_lis, int n, int cur_lis_size);
int		*lis_rec(int *stack, int s_len, int *cur_lis, t_push *push);
void	find_lis(t_push *push);

void	free_all(t_push *push);

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

#endif
