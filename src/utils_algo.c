/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 06:51:25 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/22 20:05:17 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	chunk_sorted_a(int *stack, int mid, int len)
{
	int	i;

	i = 0;
	while (i <= len)
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
	while (i <= len)
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

	key = stack[len / 2];
	return (key);
}

int	*algo_secret(int *stack, int len)
{
	int	i;
	int	temp;
	int	*ustack;

	i = 0;
	ustack = malloc(sizeof(int) * len);
	ft_memcpy(ustack, stack, sizeof(int) * (len + 1));
	while (i < len)
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
