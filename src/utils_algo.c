/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 06:51:25 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/29 00:41:43 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
