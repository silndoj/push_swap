/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:52:06 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/07 07:16:11 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	algorithm_1(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	int	i;
	int	pos;
	int	temp;

	i = 0;
	pos = 0;
	temp = stack_a[0];
	while (*len_a >= 3)
	{
		i = 0;
		pos = 0;
		temp = stack_a[0];
		while (i <= *len_a)
		{
			if (temp > stack_a[i])
			{
				temp = stack_a[i];
				pos = i;
			}
			i++;
		}
		road_top(stack_a, pos, *len_a);
		trick_pb(stack_b, stack_a, len_b, len_a);
	}
	sort_3(stack_a, *len_a);
}

int	*algo_secret(int *stack_a, int len_a)
{
	int	i;
	int	j;
	int	temp;
	int	*stack_scr;

	i = 0;
	j = 0;
	temp = stack_a[0];
	stack_scr = malloc(sizeof(int) * len_a);
	while (len_a >= 0)
	{
		i = 0;
		while (i <= len_a)
		{
			if (temp > stack_a[i])
				temp = stack_a[i];
			i++;
		}
		stack_scr[j] = temp;
		j++;
		len_a--;
	}
	return (stack_scr);
}

//void	algorithm_100(int *stack_a, int *stack_b, int *len_a, int *len_b)
//{
//	int	chunk_temp;
//	int	i;
//
//	i = 0;
//	chunk_temp = stack_a[*len_a / 4];
//	while (i <= *len_a)
//	{
//		if (stack_a[i] <= chunk_temp)
//		{
//			road_top(stack_a, i, *len_a);
//			trick_pb(stack_b, stack_a, len_b, len_a);
//		}
//		i++;
//	}
//	i = 1
//	while (i <= *len_a)
//	{
//		if (stack_a[i] <= chunk_temp)
//		{
//			road_top(stack_a, i, *len_a);
//			trick_pb(stack_b, stack_a, len_b, len_a);
//		}
//		i++;
//	}
//
//}

void	algorithm_2(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	if (*len_a < 100)
	{
		algorithm_1(stack_a, stack_b, len_a, len_b);
		push_all_a(stack_a, stack_b, len_a, len_b);
	}
	if (*len_a == 4)
		sort_5(stack_a, stack_b, len_a, len_b);
	if (*len_a == 3)
		sort_4(stack_a, stack_b, len_a, len_b);
	if (*len_a == 2)
		sort_3(stack_a, *len_a);
	if (*len_a == 1)
		sort_2(stack_a, *len_a);
}
