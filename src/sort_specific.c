/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_specific.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:22:45 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/11 03:33:16 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_sorted(int *stack_a, int len_a)
{
	int	i;

	i = 0;
	while (i < len_a)
	{
		if (stack_a[i] < stack_a[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}

void	sort_2(int *stack, int len_a)
{
	if (stack[0] > stack[1])
		trick_sa(stack, len_a);
}

void	sort_3(int *stack, int len_a)
{
	len_a = 2;
	if (stack[0] > stack[1] && stack[1] < stack[2]
		&& stack[2] > stack[0])
		trick_sa(stack, len_a);
	else if (stack[0] > stack[1] && stack[1] > stack[2]
		&& stack[2] < stack[0])
	{
		trick_sa(stack, len_a);
		trick_rra(stack, len_a);
	}
	else if (stack[0] > stack[1] && stack[1] < stack[2]
		&& stack[2] < stack[0])
		trick_ra(stack, len_a);
	else if (stack[0] < stack[1] && stack[1] > stack[2]
		&& stack[2] > stack[0])
	{
		trick_sa(stack, len_a);
		trick_ra(stack, len_a);
	}
	else if (stack[0] < stack[1] && stack[1] > stack[2]
		&& stack[2] < stack[0])
		trick_rra(stack, len_a);
}

void	sort_4(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	if (check_sorted(stack_a, *len_a))
	{
		if (!check_sorted(stack_a, 2) && stack_a[3] < stack_a[0])
			trick_rra(stack_a, *len_a);
		else if (check_sorted(stack_a, 2))
		{
			trick_pb(stack_b, stack_a, len_b, len_a);
			sort_3(stack_a, *len_a);
			trick_pa(stack_a, stack_b, len_a, len_b);
			if (stack_a[0] < stack_a[2] && stack_a[0] > stack_a[1])
				trick_sa(stack_a, *len_a);
			else if (stack_a[0] < stack_a[3]
				&& stack_a[0] > stack_a[2])
			{
				trick_rra(stack_a, *len_a);
				trick_sa(stack_a, *len_a);
				trick_ra(stack_a, *len_a);
				trick_ra(stack_a, *len_a);
			}
			else if (stack_a[0] > stack_a[3])
				trick_ra(stack_a, *len_a);
		}
	}
}

void	sort_5(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	int	i;
	int	*restack;

	i = 0;
	restack = algo_secret(stack_a, *len_a);
	while (i++ <= *len_a)
	{
		if (stack_a[i] == restack[*len_a - 1])
			road_top_a(stack_a, i, *len_a);
	}
	i = 0;
	trick_pb(stack_b, stack_a, len_b, len_a);
	while (i++ <= *len_a)
	{
		if (stack_a[i] == restack[*len_a + 1])
			road_top_a(stack_a, i, *len_a);
	}
	trick_pb(stack_b, stack_a, len_b, len_a);
	sort_3(stack_a, *len_a);
	trick_pa(stack_a, stack_b, len_a, len_b);
	trick_pa(stack_a, stack_b, len_a, len_b);
	trick_ra(stack_a, *len_a);
	trick_ra(stack_a, *len_a);
	free(restack);
}
