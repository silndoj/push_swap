/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricks_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:31:45 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/23 20:48:31 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	trick_sa(int *stack_a, int len_a)
{
	int	temp;

	if (len_a > 1)
	{
		temp = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = temp;
		ft_printf("sa\n");
	}
}

void	trick_pa(int **stack_a, int **stack_b, int *len_a, int *len_b)
{
	if (*len_b >= 0)
	{
		if (*len_a > 0)
			*stack_a = ft_plus_stack(*stack_a, *len_a);
		*len_a += 1;
		(*stack_a)[0] = (*stack_b)[0];
		*stack_b = ft_minus_stack(*stack_b, *len_b);
		*len_b -= 1;
		ft_printf("pa\n");
	}
}

void	trick_ra(int *stack_a, int len_a)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack_a[i];
	while (i < len_a - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[len_a - 1] = temp;
	ft_printf("ra\n");
}

void	trick_rra(int *stack_a, int len_a)
{
	int	i;
	int	temp;

	i = len_a - 1;
	temp = stack_a[i];
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = temp;
	ft_printf("rra\n");
}
