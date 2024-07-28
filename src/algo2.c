/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:07:07 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/28 02:53:09 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	*push_all_b(int **stack_a, int **stack_b, int *len_a, int *len_b)
{
	int	*chunk_arr_b;
	int chunk;
	int	i;

	i = 1;
	chunk_arr_b = malloc(sizeof(int));
	chunk = push_b(stack_a, stack_b, len_a, len_b);
	chunk_arr_b[0] = chunk;
	while (*len_a > 2)
	{
		chunk = push_b(stack_a, stack_b, len_a, len_b);
		chunk_arr_b = ft_new_chunk(chunk_arr_b, chunk, i);
		i++;
	}
	chunk_arr_b = ft_new_chunk(chunk_arr_b, i, i);
	chunk_arr_b = ft_new_chunk(chunk_arr_b, 0, i + 1);
	chunk_arr_b = ft_new_chunk(chunk_arr_b, -1, i + 2);
	sort_2(*stack_a, *len_a);
	return (chunk_arr_b);
}
