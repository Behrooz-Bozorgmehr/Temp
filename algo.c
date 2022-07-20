/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:01:30 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/07/20 20:47:41 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"


/*void	b_algo(t_stack *b)
{
	int	size;

	size = lst_size(b);
	if (size >= 2)
	{
		if (b->val < b->next->val)
			sb(b);
	}
}
*/
/*
void	a_algo(t_stack **a, t_stack *head, t_stack *tail, t_stack **b)
{
	int	sorted;

	sorted = check_order(*a);
	while (sorted == 0 || lst_size(*b) != 0)
	{
		if (tail->val < head->val && tail->val < head->next->val)
			rra(a);
		else if (head->next->val < head->val && head->next->val > tail->val)
			sa(*a);
		else if (head->next->val < tail->val && head->val > tail->val)
			ra(a);
		else if (tail->val < head->val)
			rra(a);
		else if (head->next->val < head->val)
			sa(*a);
		else if ((head->val < head->next->val && ((*b) == NULL
					|| (*a)->val < (*b)->val)) || sorted == 0)
			pb(b, a);
		sorted = check_order(*a);
		if ((sorted && (*b) != NULL) && (*a)->val < (*b)->val)
			pb(b, a);
		else if ((sorted && (*b) != NULL) && (*a)->val > (*b)->val)
			pa(a, b);
		head = *a;
		tail = lst_last(*a);
	}
}
*/
void	algo_3_b(t_stack **b)
{
//	print(NULL, *b);
//	write(1, "in_algo_b\n", 10); 
	int	val;
	int n_val;
	int p_val;

	val = (*b)->val;
	n_val = (*b)->next->val;
	p_val = (*b)->prev->val;
	if (lst_size(*b) < 3 && val < n_val)
		sb(*b);
	else if (val < p_val && n_val >p_val)
		rb(b);
	else if (val < n_val && p_val >n_val)
	{
		rb(b);
		sb(*b);
	}
	else if (val < n_val && val > p_val)
	   sb(*b);
	else if (val > n_val && n_val < p_val)
		rrb(b);
	else if (val > n_val && n_val < p_val)
	{
		rrb(b);
		sb(*b);
	}
//	print(NULL, *b);
}

void	algo_3(t_stack **a)
{
//	write(1, "in_algo_3\n", 10);
	int	val;
	int n_val;
	int p_val;

	val = (*a)->val;
	n_val = (*a)->next->val;
	p_val = (*a)->prev->val;
	if (lst_size(*a) < 3 && val > n_val)
		sa(*a);
	else if (val < p_val && n_val >p_val)
	{
		rra(a);
		sa(*a);
	}
	else if (val > n_val && p_val > val)
		sa(*a);
	else if (val < n_val && val > p_val)
	   rra(a);
	else if (val > n_val && n_val > p_val)
	{
		sa(*a);
		rra(a);
	}
	else if (val > n_val && n_val < p_val)
	{
		rra(a);
		rra(a);
	}
}	

void	algo_5_b(t_stack **b, t_stack **a)
{
	int	size;
	int	i;

	size = lst_size(*b);
	if (check_reverse_order(*b) == 0 ) 
	{
		i = size;
		while (i-- > 3)
			pa(a, b);
		if ((*a)->val > (*a)->next->val)
			sa(*a);
		algo_3_b(b);
		while (size != lst_size(*b))
		{
			if ((*a)->val < lst_last(*b)->val)
			{
				pb(b, a);
				rb(b);
			}
			else if ((*a)->val < lst_last(*b)->prev->val)
			{
				rrb(b);
				pb(b, a);
				rb(b);
				rb(b);
			}
			else if ((*a)->val < (*b)->next->val)
			{
				rb(b);
				rb(b);
				pb(b, a);
				rrb(b);
				rrb(b);
			}
			else if ((*a)->val < (*b)->val)
			{
				pb(b, a);
				sb(*b);
			}
		}
	}
}

void	algo_5(t_stack **a, t_stack **b)
{
	int	val;
	int	n_val;
	int	p_val;
	int size;

	size = lst_size(*a);
	while (check_order(*a) == 0 || lst_size(*a) != size)
	{
		while (lst_size(*a) > 3 && check_order(*a) == 0)
		{
			val = (*a)->val;
			n_val = (*a)->next->val;
			p_val = (*a)->prev->val;
			if (val < n_val && val < p_val)
				pb(b, a);
			else if (val > n_val)
				sa(*a);
			else if (p_val < val)
				rra(a);
		}
		if (lst_size(*a) == 3)
			algo_3(a);
		if (lst_size(*b) == 2 && check_order(*b) == 1) // should be inversly ordered
			sb(*b);
		else if (*b != NULL)
			pa(a, b);
	}
}

/*

void	algo_b(t_stack **b, t_stack **a)
{
	int	val;
	int n_val;
	int p_val;
	while(lst_size(*b) > 0)
	{
		val = (*a)->val;
		n_val = (*a)->next->val;
		p_val = (*a)->prev->val;
		int	pos = position(*a, minimum);
		int max = maximum(*a);
		int size = lst_size(*a);
		if (val == max)
			pa(a, b);
		else if (pos > size / 2 +1)
			rrb(b);
		else if (pos <= size / 2 + 1)
			rb(b);
	}
}

*/
/*
void	algo_big(t_stack **a, t_stack **b)
{
	int	val;
	int	pos;
	int	min;

	while (check_order(*a) == 0)
	{
		while (lst_size(*a) > 3 && check_order(*a) == 0)
		{
			val = (*a)->val;
			pos = position(*a, minimum);
			min = minimum(*a);
			if (val == min)
			else if (pos > (lst_size(*a) / 2 + 1))
				rra(a);
			else if (pos <= (lst_size(*a) / 2 + 1))
				ra(a);
		}
		if (lst_size(*a) == 3)
			algo_3(a);
	}
	while (*b != NULL)
		pa(a, b);
}
*/
// function is called if & only if stack is not sorted
/*void	algo(t_stack **a, t_stack **b)
{
	int size;
	int	*count;

	*count = 0;
	size = lst_size(*a);
	if (size == 2)
		sa(*a);
	else if (size ==  3)
		algo_3(a, 0, 0, 0);
//	else if (size <= 5)
//		algo_5(a, b);
	else //if(size > 5)
	//		algo_big(a, b);
		algo_large(a, b, size, count);
}

*/

void	part_a(t_stack	**a, t_stack	**b, t_operation *op)
{
	if ((*a)->pos > op->pvt_a)
	{
		op->ra++;
	   	ra(a);
	}	
	else
	{
		op->pb++;
	   	pb(b, a);
		if ((*b)->pos > op->pvt_b)
		{
			op->rb++;
		    rb(b);
		}
	}
}

void	reverse_a(t_stack	**a, t_stack	**b, t_operation	*op, int	*count)
{
//	write(1, "in_reverse_a\n", 13);
	int	i;
	int	j;

	i = op->rb;
	j = op->ra - i;
	if ((*count) > 0)
	{
		while (i--)
			rrr(a, b);
		while (j--)
			ra(a);
	}
	else
	{
		while (i--)
			rb(b);
	}
}


void	reverse_ra(t_stack	**a, t_stack	**b, t_operation	*op)
{
//	write(1, "in_reverse_ra\n", 14);
	int	i;
	int	j;

	i = op->rb;
	j = op->ra - i;
	while (i--)
		rrr(a, b);
	while (j--)
		ra(a);
}

void	reverse_b(t_stack	**a, t_stack	**b, t_operation	*op, int	*count)
{
//	write(1, "in_reverse_b\n", 13);
	int	i;
	int	j;

	i = op->ra;
	j = op->rb - i;
	if ((*count) > 0)
	{
		while (i--)
			rrr(a, b);
		while (j--)
			rb(b);
	}
	else
	{
		i = op->rb;
		while (i--)
			rb(b);
	}
}

void	part_b(t_stack	**a, t_stack	**b, t_operation *op)
{
//	write(1, "in_part_b\n", 10);
	if ((*b)->pos <= op->pvt_b)
	{
		 rb(b);
		op->rb++;
	}
	else
	{	
		pa(a, b);
		op->pa++;
		if ((*a)->pos <= op->pvt_a)
		{
			ra(a);
			op->ra++;
		}
	}
}

void	reverse_rb(t_stack	**a, t_stack**b, t_operation	*op)
{
	int	i;
	int	j;
//	write(1, "in_reverse_rb", 15);
	i = op->ra;
	j = op->rb - i;
	while (i--)
		rrr(a, b);
	while (j--)
		rb(b);
}
void	uno_dos_tres(t_stack **a, t_stack **b, int size, int flag)
{
	if (size <= 3)
	{
		if (flag == 'A')
			algo_3(a);
		else
			algo_3_b(b);
	}
		
}

int	small_nbr(t_stack **a, t_stack **b, int size, int flag)
{
	if (flag == 'A' && size <= 5)
	{
		if (size <= 3 )
			algo_3(a);
		else
			algo_5(a, b);
	//	while ((*a)->val < (*b)->val )
	//		pb(b, a);
		return (1);
	}
	else if (flag == 'B' && size <= 5) 
	{
		if (size <= 3)
			algo_3_b(b);
		else
			algo_5_b(b, a);
		while (*b != NULL)
			pa(a, b);
		return (1);
	}
	return (0);
}
void	algo_big_b(t_stack **a, t_stack **b, int size, int *count)
{
//	write(1, "in_algo_big_b\n", 14);
	t_operation	op;
	t_pivot		pvt;
	int			i;

	(*count)++;
	if (small_nbr(a,b, size, 'B'))
	{
		return ;
	}
	init_ops(&op);
	init_pivots(*b, &op);
	i = size;
	while (i-- )
		part_b(a, b, &op);
	algo_big_a(a, b, op.pa - op.ra, count);
	if (op.ra > op.rb)
		reverse_ra(a, b, &op);
	else //if (op.ra < op.rb)
		reverse_rb(a, b, &op);
	algo_big_a(a, b, op.ra, count);
	algo_big_b(a, b, op.rb, count);
}

void	algo_big_a(t_stack **a, t_stack **b, int size, int *count)
{
//	write(1, "in_algo_big_a\n",14);
	t_operation	op;
	t_pivot		pvt;
	int			i;
	if (small_nbr(a, b, size, 'A'))
	{
		return ;
	}
	init_ops(&op);
	init_pivots(*a, &op);
		i = size;
	while (i-- )
		part_a(a, b, &op);
	if (op.ra > op.rb)
		reverse_a(a, b, &op, count);
	else //if (op.ra < op.rb)
		reverse_b(a, b, &op, count);
	algo_big_a(a, b, op.ra, count);
	algo_big_b(a, b, op.rb, count);
	algo_big_b(a, b, op.pb - op.rb, count);
}
