/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:01:45 by silndoj           #+#    #+#             */
/*   Updated: 2024/08/01 01:00:24 by silndoj          ###   ########.fr       */
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
		trick_rrb(&stack_b, len_b);
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
