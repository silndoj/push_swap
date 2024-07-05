/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_specific.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:22:45 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/06 00:25:24 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_3(int *stack, int len_a)
{
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

void	sort_5(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	trick_pb(stack_b, stack_a, len_b, len_a);
	trick_pb(stack_b, stack_a, len_b, len_a);
	sort_3(stack_a, *len_a);
	if (stack_b[1] > stack_b[0])
		trick_sb(stack_b, *len_b);
	if (stack_b[0] < stack_a[2])
	{
		trick_pa(stack_a, stack_b, len_a, len_b);
		sort_3(stack_a, 2);
		trick_pa(stack_a, stack_b, len_a, len_b);
		sort_3(stack_a, 2);
	}
	else if (stack_b[0] > stack_a[2] && stack_b[1] > stack_a[2])
	{
		trick_pa(stack_a, stack_b, len_a, len_b);
		trick_pa(stack_a, stack_b, len_a, len_b);
		trick_ra(stack_a, *len_a);
		trick_ra(stack_a, *len_a);
	}
	else
	{
		trick_pa(stack_a, stack_b, len_a, len_b);
		trick_ra(stack_a, *len_a);
		trick_pa(stack_a, stack_b, len_a, len_b);
		sort_3(stack_a, 2);
	}
}
