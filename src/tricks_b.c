/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricks_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 03:41:00 by silndoj           #+#    #+#             */
/*   Updated: 2024/08/03 07:02:34 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	trick_sb(int *stack_b, int len_b)
{
	int	temp;

	if (len_b > 1)
	{
		temp = stack_b[0];
		stack_b[0] = stack_b[1];
		stack_b[1] = temp;
		ft_printf("sb\n");
	}
}

void	trick_pb2(t_stack *b, t_stack *a)
{
	if (a->len >= 0)
	{
		if (b->len > 0)
			b->stack = ft_plus_stack(b->stack, b->len);
		b->len += 1;
		(b->stack)[0] = (a->stack)[0];
		a->stack = ft_minus_stack(a->stack, a->len);
		a->len -= 1;
		ft_printf("pb\n");
	}
}

void	trick_pb(int **stack_b, int **stack_a, int *len_b, int *len_a)
{
	if (*len_a >= 0)
	{
		if (*len_b > 0)
			*stack_b = ft_plus_stack(*stack_b, *len_b);
		*len_b += 1;
		(*stack_b)[0] = (*stack_a)[0];
		*stack_a = ft_minus_stack(*stack_a, *len_a);
		*len_a -= 1;
		ft_printf("pb\n");
	}
}

void	trick_rb(int **stack_b, int len_b)
{
	int	i;
	int	temp;

	i = 0;
	temp = (*stack_b)[i];
	while (i < len_b - 1)
	{
		(*stack_b)[i] = (*stack_b)[i + 1];
		i++;
	}
	(*stack_b)[len_b - 1] = temp;
	ft_printf("rb\n");
}

void	trick_rrb(int **stack_b, int len_b)
{
	int	i;
	int	temp;

	i = len_b - 1;
	temp = (*stack_b)[i];
	while (i > 0)
	{
		(*stack_b)[i] = (*stack_b)[i - 1];
		i--;
	}
	(*stack_b)[0] = temp;
	ft_printf("rrb\n");
}
