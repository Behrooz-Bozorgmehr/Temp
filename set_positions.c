
#include "push_swap.h"

int	*define_position(t_stack *lst)
{
	int i;
	int j;
	int	*ptr;
	int	size = lst_size(lst);

	if (lst != NULL)
	{
		ptr = (int *)malloc (sizeof(int) * size);	
		if (ptr != NULL)
		{
			i = 0;
			while (i < size)
			{
				ptr[i++] = lst->val;
				lst = lst->next;
			}
			quick_sort(ptr, 0, size - 1);		
			return (ptr);
		}
	}
	return (0);
}

void	set_position(t_stack *lst, int ptr[])
{
	int	i;
	int	size;

	size = lst_size(lst);

	while (lst != NULL)
	{
		i = -1;
		while (++i < size)
		{
			if (lst->val == ptr[i])
			{
				lst->pos = i;
				break;
			}
		}
		lst = lst->next;
	}
//	while(--size > 0)
//		ptr[size] = 0;
	free (ptr);
	ptr = NULL;

}

void	quick_sort(int arg[], int start, int end)
{
	int ndx;

	if (start < end)
	{
		ndx = partition(arg, start, end);
		quick_sort(arg, start, ndx - 1);
		quick_sort(arg, ndx + 1, end);
	}
}	

int	partition(int arg[], int start, int end)
{
	int	i;
	int j;
	int	temp;

	i = start - 1;
	j = start;
	while (j <= end)
	{
		if (arg[j] <= arg[end])
		{	
			i++;
			if (i != j)
			{
                temp = arg[i];
				arg[i] = arg[j];
				arg[j] = temp;
				j = i;
			}
		}
		j++;
	}
	return (i);
}
