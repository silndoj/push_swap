/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:01:45 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/28 03:05:55 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/push_swap.h"

void sort_2b(int *stack_b, int len_b)
{
	if (stack_b[0] < stack_b[1])
		trick_sb(stack_b, len_b);
}

void	back_top_b(int *stack_b, int b, int len_b)
{
	while (b > 0)
	{
		trick_rrb(stack_b, len_b);
		b--;
	}
}

int	chunk_control_b(int	*stack_b, int chunk_len)
{
	int i;

	i = 0;
	while (i < chunk_len)
	{
		if (stack_b[i] > stack_b[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}

int	chunk_sorted_b(int *stack, int mid, int len)

{
	int	i;

	i = 0;
	while (i < len)
	{
		if (stack[i] > mid)
			return (1);
		i++;
	}
	return (0);
}

//int	push_big_a(int **stack_a, int **stack_b, int *len_a, int *len_b)
//{
//	int	i;
//	int b;
//	int	half;
//	int	pos;
//	int	restack;
//
//	pos = 0;
//	half = *len_b / 2;
//	while (*len_b >= half)
//	{
//		i = 0;
//		restack = (*stack_b)[0];
//		while (i <= half)
//		{
//			if (restack < ((*stack_b)[i]))
//			{
//				restack = ((*stack_b)[i]);
//				pos = i;
//			}
//			i++;
//		}
//		b = road_b_top(stack_b, pos, *len_b);
//		trick_pa(stack_a, stack_b, len_a, len_b);
//		back_top_b(*stack_b, b, *len_b);
//	}
//	return (half);
//}

