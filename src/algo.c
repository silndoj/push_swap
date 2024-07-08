/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:52:06 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/08 19:33:32 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	alg_basic_a(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	int	i;
	int	temp;
	int	pos;

	while (*len_a >= 0)
	{
		i = 0;
		temp = stack_a[0];
		pos = 0;
		while (i <= *len_a)
		{
			if (temp > stack_a[i])
			{
				temp = stack_a[i];
				pos = i;
			}
			i++;
		}
		road_top(stack_a, pos, *len_a);
		trick_pb(stack_b, stack_a, len_b, len_a);
	}
}

void	alg_basic_b(int *stack_b, int *stack_a, int *len_b, int *len_a)
{
	int	i;
	int	temp;
	int	pos;

	while (*len_b >= 0)
	{
		i = 0;
		temp = stack_b[0];
		pos = 0;
		while (i <= *len_b)
		{
			if (temp < stack_b[i])
			{
				temp = stack_b[i];
				pos = i;
			}
			i++;
		}
		road_top(stack_b, pos, *len_b);
		trick_pa(stack_a, stack_b, len_a, len_b);
	}
}

void	algorithm_100(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	push_chunk(stack_a, stack_b, len_a, len_b);
	alg_basic_a(stack_a, stack_b, len_a, len_b);
	alg_basic_b(stack_b, stack_a, len_b, len_a);
}
