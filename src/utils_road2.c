/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_road2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 02:51:15 by silndoj           #+#    #+#             */
/*   Updated: 2024/08/04 11:55:19 by silndoj          ###   ########.fr       */
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
		rra_road(&stack_a, mid, &len_a, &flag);
		ra_road(&stack_a, mid, &len_a, &flag);
	}
}

void	road_top_a(int *stack_a, int mid, int len_a)
{
	int	flag;

	flag = 0;
	while (flag == 0)
	{
		if (stack_a[0] < mid)
			flag = 1;
		if (stack_a[len_a - 1] < mid && flag == 0)
		{
			trick_rra(&stack_a, len_a);
			flag = 1;
		}
		else if (flag == 0)
			ra_top(&stack_a, mid, &len_a, &flag);
	}
}

int	road_top_a2(int **stack_a, int mid, int len_a)
{
	int	flag;
	int	a;

	a = 0;
	flag = 0;
	while (flag == 0)
	{
		if ((*stack_a)[0] < mid)
			flag = 1;
		else if (flag == 0)
			a = ra_top1(&stack_a, mid, &len_a, &flag);
	}
	return (a);
}

int	road_top_b(int **stack_b, int mid, int len_b)
{
	int	flag;
	int	b;

	b = 0;
	flag = 0;
	while (flag == 0)
	{
		if ((*stack_b)[0] > mid)
			flag = 1;
		else
			b = rb_top(&stack_b, mid, &len_b, &flag);
	}
	return (b);
}
