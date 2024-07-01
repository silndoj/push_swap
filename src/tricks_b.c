/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricks_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 03:41:00 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/01 04:09:52 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	trick_sb(int *stack_b, int len_b)
{
	int	temp;

	if (len_b <= 2)
		return (1);
	temp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = temp;
	ft_printf("sb\n");
	return (0);
}

int	trick_pb(int *stack_b, int *stack_a, int len_b, int len_a)
{
	int	i;
	int	t1;
	int	t2;

	i = 0;
	if (!stack_b[0])
		return (1);
	while (i <= len_b)
	{
		if (i == 0)
		{
			t1 = stack_b[i];
			stack_b[i] = stack_a[0];
		}
		else if (i != 0)
		{
			t2 = stack_b[i];
			stack_b[i] = t1;
			t1 = t2;
		}
		i++;
	}
	ft_printf("pb\n");
	return (0);
}
