#include "push_swap.h"

int	maximum(t_stack *lst)
{
	int	max;
	
	max = lst->pos;
	while (lst != NULL && lst->next != NULL)
	{
		lst = lst->next;
		if (lst->pos > max)
			max = lst->pos;
	}
	return (max);
}
int	minimum(t_stack *lst)
{
	int	min;
	
	min = lst->pos;
	while (lst != NULL && lst->next != NULL)
	{
		lst = lst->next;
		if (lst->pos < min)
			min = lst->pos;
	}
	return (min);
}

int	position(t_stack *lst, int (*func)(t_stack *))
{
	int	pos;
	int	min;

	pos = 0;
	min = func(lst);
	while (lst != NULL)
	{
		pos++;
		if (lst->val == min)
			return (pos);
		lst = lst->next;
	}
	return (pos);
}
