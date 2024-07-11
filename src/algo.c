/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:52:06 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/11 11:04:12 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	road_top_a(int *stack_a, int mid, int len_a)
{
	int	flag;
	int	i;

	i = 0;
	flag = 0;
	while (flag == 0)
	{
		if (stack_a[0] < mid)
			flag = 1;
		if(stack_a[len_a] < mid && flag == 0)
		{
			trick_rra(stack_a, len_a);
			flag = 1;
		}
		else if (flag == 0)
		{
			while (i == 0)
			{
				if (stack_a[0] > mid)
					trick_ra(stack_a, len_a);
				else
				 i = 1;
			}
			flag = 1;
		}
	}
}

void	road_top_b(int *stack_b, int mid, int len_b)
{
	int	flag;
	int	i;

	i = 0;
	flag = 0;
	while (flag == 0)
	{
		if (stack_b[0] > mid)
			flag = 1;
		if(stack_b[len_b] > mid && flag == 0)
		{
			trick_rrb(stack_b, len_b);
			flag = 1;
		}
		else if (flag == 0)
		{
			while (i == 0)
			{
				if (stack_b[0] < mid)
					trick_rb(stack_b, len_b);
				else
				 i = 1;
			}
			flag = 1;
		}
	}
}

void	push_b(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	int	i;
	int	flag;
	int	mid;
	int	*restack;

	i = 0;
	flag = 0;
	restack = algo_secret(stack_a, *len_a);
	mid = mid_key(restack, *len_a);
	while (*len_a >= 0 && flag == 0)
	{
		road_top_a(stack_a, mid, *len_a);
		trick_pb(stack_b, stack_a, len_b, len_a);
		if (!chunk_sorted_a(stack_a, mid, *len_a))
			flag = 1;
	}
}

void  algo_100(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	int	chunk_nr;

	chunk_nr = 0;;
	while (*len_a > 1)
	{
		push_b(stack_a, stack_b, len_a, len_b);
		chunk_nr++;
	}
	sort_2(stack_a, *len_a);
	push_a(stack_b, stack_a, len_b, len_a);
}

void  algo_union(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	if (*len_a == 1 && check_sorted(stack_a, *len_a))
		sort_2(stack_a, *len_a);
	if (*len_a == 2 && check_sorted(stack_a, *len_a))
		sort_3(stack_a, *len_a);
	if (*len_a == 3 && check_sorted(stack_a, *len_a))
		sort_4(stack_a, stack_b, len_a, len_b);
	if (*len_a == 4 && check_sorted(stack_a, *len_a))
		sort_5(stack_a, stack_b, len_a, len_b);
	else if (*len_a > 4 && *len_a < 100
		&& check_sorted(stack_a, *len_a))
		algo_100(stack_a, stack_b, len_a, len_b);
}
