/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:49:52 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/07 06:05:21 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char *argv[])
{
	int	i;
	int	*stack_a;

	i = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		if (ft_error_single(argv[1]))
			return (1);
		stack_a = sstack_trick(argv[1]);
	}
	else if (argc > 2)
	{
		if (ft_error(argv))
			return (1);
		stack_a = stack_trick(argv, argc - 2);
	}
	ft_printf("\n\n");
	ft_printf("--------------------\n");
	while (i <= (argc - 2))
	{
		ft_printf("| stack[%d] = %d\n", i, stack_a[i]);
		i++;
	}
	ft_printf("--------------------\n");
	return (0);
}
