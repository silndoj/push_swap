/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 06:51:25 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/28 03:07:33 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	back_top_a(int *stack_a, int a, int len_a)
{
	while (a > 0)
	{
		trick_rra(stack_a, len_a);
		a--;
	}
}

int	chunk_sorted_a(int *stack, int mid, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (stack[i] < mid)
			return (1);
		i++;
	}
	return (0);
}
