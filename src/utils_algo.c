/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 06:51:25 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/23 21:28:22 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

int	*algo_secret(int *stack, int len)
{
	int	i;
	int	temp;
	int	*ustack;

	i = 0;
	ustack = malloc(sizeof(int) * len);
	ft_memcpy(ustack, stack, sizeof(int) * len);
	while (i < len - 1)
	{
		if (ustack[i] > ustack[i + 1])
		{
			temp = ustack[i];
			ustack[i] = ustack[i + 1];
			ustack[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	return (ustack);
}
