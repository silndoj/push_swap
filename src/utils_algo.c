/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 06:51:25 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/07 06:59:04 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    road_top(int *stack_a, int pos, int len_a)
{
	int	i;
	int	nr;

	i = 0;
	nr = stack_a[pos];
	if (pos <= (len_a / 2) && pos != 0)
	{
		while (i == 0)
		{
			trick_ra(stack_a, len_a);
			if (stack_a[0] == nr)
			i = 1;
		}
	}
	else if (pos > (len_a / 2) && pos != 0)
	{
		while (i == 0)
		{
			trick_rra(stack_a, len_a);
			if (stack_a[0] == nr)
			i = 1;
		}
	}
}

void    push_all_a(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	while (*len_b >= 0)
		trick_pa(stack_a, stack_b, len_a, len_b);
}
