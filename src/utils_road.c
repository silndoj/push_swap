/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_road.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:16:26 by silndoj           #+#    #+#             */
/*   Updated: 2024/08/03 08:41:27 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	back_top_a(int *stack_a, int a, int len_a)
{
	while (a > 0)
	{
		trick_rra(&stack_a, len_a);
		a--;
	}
}

void	rra_road(int **stack_a, int mid, int *len_a, int *flag)
{
	int	temp;

	temp = (*stack_a)[mid];
	while (*flag == 0 && mid >= ((*len_a - 1) / 2) + 1)
	{
		trick_rra(stack_a, *len_a);
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
		trick_ra(stack_a, *len_a);
		if ((*stack_a)[0] == temp)
			*flag = 1;
	}
}

int	ra_top(int **stack_a, int mid, int *len_a, int *flag)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (i == 0)
	{
		if ((*stack_a)[0] >= mid)
		{
			trick_ra(stack_a, *len_a);
			a++;
		}
		else
			i = 1;
	}
	*flag = 1;
	return (a);
}

int	ra_top1(int ***stack_a, int mid, int *len_a, int *flag)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (i == 0)
	{
		if ((**stack_a)[0] >= mid)
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
