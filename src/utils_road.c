/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_road.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:16:26 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/28 00:39:36 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rra_road(int **stack_a, int mid, int *len_a, int *flag)
{
	int	temp;

	temp = (*stack_a)[mid];
	while (*flag == 0 && mid >= ((*len_a - 1) / 2) + 1)
	{
		trick_rra(*stack_a, *len_a);
		if ((*stack_a)[0] == temp)
			*flag = 1;
	}	
}

void	ra_road(int **stack_a, int mid, int *len_a, int *flag)
{
	int	temp;

	temp = (*stack_a)[mid];
	while (*flag == 0 && mid < ((*len_a - 1) / 2) + 1)
	{
		trick_ra(*stack_a, *len_a);
		if ((*stack_a)[0] == temp)
			*flag = 1;
	}	
}

int	ra_top(int **stack_a, int mid, int *len_a, int *flag)
{
	int	i;
	int a;

	i = 0;
	a = 0;
	while (i == 0)
	{
		if ((*stack_a)[0] > mid)
		{
			trick_ra(*stack_a, *len_a);
			a++;
		}
		else
			i = 1;
	}
	*flag = 1;
	return (a);
}

int	rrb_top(int **stack_b, int mid, int *len_b, int *flag)
{
	int rrb;

	rrb = 0;
	trick_rrb(*stack_b, *len_b);
	rrb++;
	*flag = 1;
	return (rrb);
}

int	rb_top(int **stack_b, int mid, int *len_b, int *flag)
{
	int rb;
	int	i;

	i = 0;
	rb = 0;
	while (i == 0)
	{
		if ((*stack_b)[0] < mid)
		{
			trick_rb(*stack_b, *len_b);
			rb++;
		}
		else
		 i = 1;
	}
	*flag = 1;
	return (rb);
}
