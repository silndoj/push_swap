/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:07:07 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/11 10:23:22 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_a(int *stack_b, int *stack_a, int *len_b, int *len_a)
{
	int	i;
	int	flag;
	int	mid;
	int	*restack;

	i = 0;
	flag = 0;
	restack = algo_secret(stack_b, *len_b);
	mid = mid_key(restack, *len_b);
	while (*len_b >= 0 && flag == 0)
	{
		road_top_b(stack_b, mid, *len_b);
		trick_pa(stack_a, stack_b, len_a, len_b);
		if (!chunk_sorted_b(stack_b, mid, *len_b))
			flag = 1;
	}
}
