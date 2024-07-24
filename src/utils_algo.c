/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 06:51:25 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/24 14:08:29 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

int	chunk_sorted_a(int *stack, int mid, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (stack[i] < mid)
			return (1);
		i++;
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

int	mid_key(int *stack, int len)
{
	int	key;

	key = stack[(len - 1) / 2];
	return (key);
}

