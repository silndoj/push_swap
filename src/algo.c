/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:52:06 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/14 17:54:06 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	road_a_top(int *stack_a, int mid, int len_a)
{
	int	flag;
	int	temp;

	flag = 0;
	temp = stack_a[mid];
	while (flag == 0)
	{
		if (stack_a[0] == temp)
			flag = 1;
		while (flag == 0 && mid >= (len_a / 2) + 1)
		{
			trick_rra(stack_a, len_a);
			if (stack_a[0] == temp)
				flag = 1;
		}
		while (flag == 0 && mid < (len_a / 2) + 1)
		{
			trick_ra(stack_a, len_a);
			if (stack_a[0] == temp)
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

void	push_big_a(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	int	i;
	int	temp;
	int	pos;

	while (*len_b >= 0)
	{
		i = 0;
		temp = stack_b[0];
		pos = 0;
		while (i <= *len_b)
		{
			if (temp < stack_b[i])
			{
				temp = stack_b[i];
				pos = i;
			}
			i++;
		}
		road_b_top(stack_b, pos, *len_b);
		trick_pa(stack_a, stack_b, len_a, len_b);
	}
}

void  algo_100(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	while (*len_a >= 1)
		push_b(stack_a, stack_b, len_a, len_b);
	sort_2(stack_a, *len_a);
	push_big_a(stack_a, stack_b, len_a, len_b);
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
	else if (*len_a > 4 && check_sorted(stack_a, *len_a))
		algo_100(stack_a, stack_b, len_a, len_b);
}
