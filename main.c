/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:45:12 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/07/17 14:00:33 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = init(argc, argv);
	b = NULL;
	sort(&a, &b);
	print(a, b);

//	printf("min: %d\t max: %d\n", minimum(a), maximum(a));
/*	int i =0;
	while (i < 12)
	{
		printf("%d\n", arr[i]);
		i++;
	}
*/
	free_list(a);
	return (0);
}
