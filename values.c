#include "push_swap.h"

int	maximum(t_stack *lst)
{
	int	max;
	
	max = lst->val;
	while (lst != NULL && lst->next != NULL)
	{
		lst = lst->next;
		if (lst->val > max)
			max = lst->val;
	}
	return (max);
}
int	minimum(t_stack *lst)
{
	int	min;
	
	min = lst->val;
	while (lst != NULL && lst->next != NULL)
	{
		lst = lst->next;
		if (lst->val < min)
			min = lst->val;
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
