
#include "push_swap.h"

void    do_checks(t_stack *lst)
{
    if (doublicated(lst) == 0)
	{
		set_position(lst, define_position(lst));
		return (lst);
	}
	else
	{
		write(STDERR, "Error\n", 6);
		free_list(lst);
		return (NULL);
	}
}

int	check_order(t_stack *lst)
{
	int	sorted;

	sorted = 1;
	while (lst->next != NULL)
	{
		if (lst->val < lst->next->val)
			sorted = 1;
		else
		{
			sorted = 0;
			return (sorted);
		}
		lst = lst->next;
	}
	return (sorted);
}
