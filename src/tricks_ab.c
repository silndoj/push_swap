/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricks_ab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 03:55:15 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/03 04:41:55 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	trick_ss(int *stack_a, int *stack_b, int len_a, int len_b)
{
	int	temp;

	if (len_a < 2 || len_b < 2)
		return (1);
	temp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp;
	temp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = temp;
	ft_printf("ss\n");
	return (0);
}

void	trick_rr(int *stack_a, int *stack_b, int len_a, int len_b)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack_a[i];
	while (i < len_a)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[len_a - 1] = temp;
	i = 0;
	temp = stack_b[i];
	while (i < len_b)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[len_b - 1] = temp;
	ft_printf("rr\n");
}

void	trick_rrr(int *stack_a, int *stack_b, int len_a, int len_b)
{
	int	i;
	int	temp;

	i = len_a;
	temp = stack_a[i - 1];
	while (i >= 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = temp;
	i = len_b;
	temp = stack_b[i - 1];
	while (i >= 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = temp;
	ft_printf("rrr\n");
}
