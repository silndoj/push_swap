/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 06:51:25 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/08 19:37:09 by silndoj          ###   ########.fr       */
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

int	*stack_copy(int *stack, int slen)
{
	int	i;
	int	*u_stack;

	i = 0;
	u_stack = malloc(sizeof(int) * slen);
	while (i <= slen)
	{
		u_stack[i] = stack[i];
		i++;
	}
	return (u_stack);
}

int	get_key(int *stack, int len, int chunk_nr)
{
	int	key;
	int	idx;

	idx = (len / 7) * chunk_nr;
	key = stack[idx + 1];
	return (key);
}

int	*algo_secret(int *stack_a, int len_a)
{
	int	i;
	int	temp;
	int	*ustack;

	i = 0;
	ustack = stack_copy(stack_a, len_a);
	while (i < len_a)
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

void	push_chunk(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 1;
	len = *len_a;
	while (j <= 6)
	{
		i = 0;
		while (i <= *len_a)
		{
			if (stack_a[i] <= get_key(algo_secret(stack_a, *len_a), len, j))
			{
				road_top(stack_a, i, *len_a);
				trick_pb(stack_b, stack_a, len_b, len_a);
				i = 0;
			}
			else
				i++;
		}
		j++;
	}
}
