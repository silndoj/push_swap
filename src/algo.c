/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:52:06 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/06 16:52:51 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	road_top(int *stack_a, int pos, int len_a)
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

void	push_all_a(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	while (*len_b >= 0)
		trick_pa(stack_a, stack_b, len_a, len_b);
}

void	algorithm_1(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	int	i;
	int	pos;
	int	temp;

	i = 0;
	pos = 0;
	temp = stack_a[0];
	while (*len_a >= 0)
	{
		i = 0;
		pos = 0;
		temp = stack_a[0];
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
	push_all_a(stack_a, stack_b, len_a, len_b);
}

void	algorithm_2(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	if (*len_a > 4)
		algorithm_1(stack_a, stack_b, len_a, len_b);
	if (*len_a == 4)
		sort_5(stack_a, stack_b, len_a, len_b);
	if (*len_a == 3)
		sort_4(stack_a, stack_b, len_a, len_b);
	if (*len_a == 2)
		sort_3(stack_a, *len_a);
	if (*len_a == 1)
		sort_2(stack_a, *len_a);
}
