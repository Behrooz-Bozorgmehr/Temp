/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:25:33 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/07/09 16:18:50 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define STDOUT 1
# define STDERR 2
typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
	struct s_stack	*prev;
	int				pos;
}	t_stack;
typedef struct	s_operation
{
	int	ra;
	int	rb;
	int	pa;
	int	pb;
}	t_operation;

typedef struct s_pivot
{
	int	a;
	int b;
}	t_pivot;
void 	init_pivots(t_stack *lst, t_pivot *pvt);
void	init_ops(t_operation *op);
int		ft_atoi(const char *str);
void	push(t_stack **lst, t_stack *elm);
t_stack	*lst_new(int value);
t_stack	*init(int size, char *arg[]);
t_stack	*lst_last(t_stack *lst);
int		lst_size(t_stack *lst);
void	lst_add_front(t_stack **lst, t_stack *elm);
int		rotate_forward(t_stack **lst);
int		rotate_backward(t_stack **lst);
int		swap(t_stack *lst);
int		check_order(t_stack *lst);
void	b_algo(t_stack *b);
void	a_algo(t_stack **a, t_stack *head, t_stack *tail, t_stack **b);

void	algo_3(t_stack **a, int val, int n_val, int p_val);
void	algo_5(t_stack **a, t_stack **b);
void	algo_big(t_stack **a, t_stack **b);
int		position(t_stack *lst, int (*func)(t_stack *));
int		minimum(t_stack *lst);
int		maximum(t_stack *lst);
void	quick_sort(int arg[], int start, int end);
int		partition(int arg[], int start, int end);
void	set_position(t_stack *lst, int arg[]);
int		*define_position(t_stack *lst);
int		pop_push(t_stack **dst, t_stack **src);
void	sort(t_stack **a, t_stack **b);
int		doublicated(t_stack *lst);
int		is_doublicated(int *arr, int size);
int		is_string(char **arg, int size);
void	free_list(t_stack *lst);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack **dst, t_stack **src);
void	pb(t_stack **dst, t_stack **src);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	print(t_stack *a, t_stack *b);
#endif /* PUSH_SWAP_H */
