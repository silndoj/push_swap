/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricks_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 03:41:00 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/03 04:25:24 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	trick_sb(int *stack_b, int len_b)
{
	int	temp;

	if (len_b < 2)
		return (1);
	temp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = temp;
	ft_printf("sb\n");
	return (0);
}

void	trick_pb(int *stack_b, int *stack_a, int *len_b, int *len_a)
{
	if (*len_a >= 0)
	{
		shift_down(stack_b, len_b);
		stack_b[0] = stack_a[0];
		shift_up(stack_a, len_a);
		ft_printf("pb\n");
	}
}

void	trick_rb(int *stack_b, int len_b)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack_b[i];
	while (i < len_b)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[len_b] = temp;
	ft_printf("rb\n");
}

void	trick_rrb(int *stack_b, int len_b)
{
	int	i;
	int	temp;

	i = len_b;
	temp = stack_b[i];
	while (i >= 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = temp;
	ft_printf("rrb\n");
}
