/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 06:51:25 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/21 23:02:49 by silndoj          ###   ########.fr       */
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

int	*stack_copy(int *stack, int slen)
{
	int	i;
	int	*u_stack;

	i = 0;
	u_stack = malloc(sizeof(int) * (slen + 1));
	while (i <= slen)
	{
		u_stack[i] = stack[i];
		i++;
	}
	u_stack[slen + 1] = '\0';
	return (u_stack);
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
	int	*dest;

	i = 0;
	dest = malloc(1 * 1);
	ustack = stack_copy(stack, len);
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
	free(dest);
	ft_memcpy(dest, ustack, len);
	free(ustack);
	return (dest);
}
