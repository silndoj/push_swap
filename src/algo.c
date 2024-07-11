/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:52:06 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/11 03:57:15 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	road_top_b(int *stack_b, int pos, int len_b)
{
	int	i;
	int	nr;

	i = 0;
	nr = stack_b[pos];
	if (pos <= (len_b / 2) && pos != 0)
	{
		while (i == 0)
		{
			trick_rb(stack_b, len_b);
			if (stack_b[0] == nr)
				i = 1;
		}
	}
	else if (pos > (len_b / 2) && pos != 0)
	{
		while (i == 0)
		{
			trick_rrb(stack_b, len_b);
			if (stack_b[0] == nr)
				i = 1;
		}
	}
}

void	alg_basic_a(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	int	i;
	int	j;
	int	*restack;

	j = 0;
	restack = algo_secret(stack_a, *len_a);
	while (*len_a >= 0)
	{
		i = 0;
		while (i <= *len_a)
		{
			if (stack_a[i] == restack[j])
			{
				road_top_a(stack_a, i, *len_a);
				trick_pb(stack_b, stack_a, len_b, len_a);
				j++;
			}
			i++;
		}
	}
	free(restack);
	restack = NULL;
}

void	alg_basic_b(int *stack_b, int *stack_a, int *len_b, int *len_a)
{
	int	i;
	int	*restack;

	restack = algo_secret(stack_b, *len_b);
	while (*len_b >= 0)
	{
		i = 0;
		while (i <= *len_b)
		{
			if (stack_b[i] == restack[*len_b])
			{
				road_top_b(stack_b, i, *len_b);
				trick_pa(stack_a, stack_b, len_a, len_b);
			}
			i++;
		}
	}
	free(restack);
	restack = NULL;
}

void	algorithm_100(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	if (*len_a == 1 && check_sorted(stack_a, *len_a))
		sort_2(stack_a, *len_a);
	if (*len_a == 2 && check_sorted(stack_a, *len_a))
		sort_3(stack_a, *len_a);
	if (*len_a == 3 && check_sorted(stack_a, *len_a))
		sort_4(stack_a, stack_b, len_a, len_b);
	if (*len_a == 4 && check_sorted(stack_a, *len_a))
		sort_5(stack_a, stack_b, len_a, len_b);
	else if (*len_a > 4 && check_sorted(stack_a, *len_a))
	{
		push_chunk(stack_a, stack_b, len_a, len_b);
		alg_basic_a(stack_a, stack_b, len_a, len_b);
		alg_basic_b(stack_b, stack_a, len_b, len_a);
	}
}
