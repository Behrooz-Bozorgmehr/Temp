
#include "push_swap.h"

t_stack	*init_step_1(t_stack *list, char *arg[], int size)
{
	int	i;
	int	value;

	i = size - 1;
	value = 0;
	if (is_string(arg, size) == 0)
	{
		if (list == NULL)
		{
			value = ft_atoi(arg[i]);
			list = lst_new(value);
			i--;
		}
		while (i >= 0)
		{
			value = ft_atoi(arg[i]);
			push(&list, lst_new(value));
			i--;
		}
		return (list);
	}
	return (NULL);
}

void    free_array(char **arr, int j)
{
   // ft_bzero(*arr, j);
	free(arr);
	arr = NULL;	
}

t_stack	*init(int size, char *arg[])
{
	int		i;
	int		j;
 	char	**ptr;
	t_stack	*list;

	i = 1;
	j = 0;
	ptr = NULL;
	list = NULL;
	if(size > 1)
	{
		while (i < size)
		{
			ptr = ft_split(arg[size - i], ' ');
			while(ptr [j] != NULL)
				j++;
			list = init_step_1(list, ptr, j);
            free_array(ptr, j);  
			j = 0;
			i++;
			if (list == NULL)
				break ;
		}
	}
    return (do_checks(list));
}


void	init_ops(t_operation *op)
{
	op->ra = 0;
	op->rb = 0;
	op->pa = 0;
	op->pb = 0;
	op->pvt_a = 0;
	op->pvt_b = 0;
}

void 	init_pivots(t_stack *lst, t_operation *op)
{
	int min;

	min = minimum(lst);
	op->pvt_a = (min + maximum(lst)) / 2;
	op->pvt_b = (min + (op->pvt_a)) / 2;
}

