/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:52:06 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/18 02:05:37 by silndoj          ###   ########.fr       */
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
	int	flag;
	int	mid;
	int	*restack;

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

void  algo_ultimate(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	int	chunk;
	int	restack;
	int len;
	int	rlen;
	int	mid;

	chunk = 0;
	while (*len_a >= 2)
	{
		push_b(stack_a, stack_b, len_a, len_b);
		chunk++;
	}
	chunk--;
	len = *len_b;
	while (*len_b >= 0)
	{
		rlen = len - (len / chunk);
		while (*len_b >= rlen)
		{
			restack = algo_secret(*stack_b, *len_b - rlen);
			mid = mid_key(restack, rlen)
		}
	}
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
		algo_ultimate(stack_a, stack_b, len_a, len_b);
}
