
#include "push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
	int	sorted;
	int size;
	int	*count;

	if (a != NULL)
	{
		sorted = check_order(*a);
		if (sorted == 0)
		{
			*count = 0;
			size = lst_size(*a);
			if (size == 2)
				sa(*a);
			else if (size ==  3)
				algo_3(a);
			//	else if (size <= 5)
			//		algo_5(a, b);
			else
				algo_big_a(a, b, size, count);
		}
	}
}
