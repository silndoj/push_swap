/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:07:07 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/24 17:11:54 by silndoj          ###   ########.fr       */
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

//void	road_b_top(int *stack_b, int mid, int len_b)
//{
//	int	flag;
//	int	temp;
//
//	flag = 0;
//	temp = stack_b[mid];
//	while (flag == 0)
//	{
//		if (stack_b[0] == temp)
//			flag = 1;
//		while (flag == 0 && mid >= (len_b / 2) + 1)
//		{
//			trick_rrb(stack_b, len_b);
//			if (stack_b[0] == temp)
//				flag = 1;
//		}
//		while (flag == 0 && mid < (len_b / 2) + 1)
//		{
//			trick_rb(stack_b, len_b);
//			if (stack_b[0] == temp)
//				flag = 1;
//		}
//	}
//}

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
		if (stack_a[len_a - 1] < mid && flag == 0)
		{
			trick_rra(stack_a, len_a);
			flag = 1;
		}
		else if (flag == 0)
			ra_top(&stack_a, mid, &len_a, &flag);
	}
}

int	road_top_b(int *stack_b, int mid, int len_b)
{
	int	flag;
	int	rb;
	int	rrb;

	rrb = 0;
	rb = 0;
	flag = 0;
	while (flag == 0)
	{
		if (stack_b[0] > mid)
			flag = 1;
		if(stack_b[len_b - 1] > mid && flag == 0)
			rrb_top(&stack_b, mid, &len_b, &flag);
		else if (flag == 0)
			rb_top(&stack_b, mid, &len_b, &flag);
	}
	if (rb)
		return (rb);
	else if (rrb)
		return (rrb);
	return (0);
}
