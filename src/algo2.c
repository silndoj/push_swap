/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:07:07 by silndoj           #+#    #+#             */
/*   Updated: 2024/08/02 23:03:24 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	push_a(int **stack_b, int **stack_a, int *ch_size, int *len_b, int *len_a, int j)
{
	int	half;
	int	flag;
	int rb;
	int	count;
	int	mid;
	int	*restack;

	half = *ch_size / 2;
	flag = 0;
	count = 0;
	restack = algo_secret2(*stack_b, *ch_size);
	count = 0;
	rb = 0;
	mid = mid_key(restack, *ch_size);
	while (*ch_size > half && flag == 0)
	{
		rb += road_top_b(stack_b, mid, *len_b);
		trick_pa(stack_a, stack_b, len_a, len_b);
		*ch_size -= 1;
		count++;
		if (!chunk_sorted_b(*stack_b, mid, *ch_size))
		{
			if (j != 0)
				back_top_b(*stack_b, rb, *len_b);
			flag = 1;
		}
	}
	free(restack);
	return (count);
}

int	push_b(int **stack_a, int **stack_b, int *len_a, int *len_b)
{
	int	flag;
	int	count;
	int	mid;
	int	*restack;

	flag = 0;
	count = 0;
	restack = algo_secret(*stack_a, *len_a);
//	if (*len_a > 100)
//		mid = mid_key1(restack, *len_a, 3);
//	else if (*len_a > 200)
//		mid = mid_key1(restack, *len_a, 5);
//	else if (*len_a > 300)
//		mid = mid_key1(restack, *len_a, 6);
//	else if (*len_a > 400)
//		mid = mid_key1(restack, *len_a, 7);
//	else
		mid = mid_key(restack, *len_a);
	while (*len_a > 2 && flag == 0)
	{
		road_top_a(*stack_a, mid, *len_a);
		trick_pb(stack_b, stack_a, len_b, len_a);
		count++;
		if (!chunk_sorted_a(*stack_a, mid, *len_a))
			flag = 1;
	}
	free(restack);
	return (count);
}

int	push_b2(int **stack_a, int **stack_b, int *len_a, int *ch_size, int *len_b)
{
	int	a;
	int	flag;
	int ra;
	int	count;
	int	mid;
	int	*restack;

	flag = 0;
	ra = 0;
	count = 0;
	restack = algo_secret2(*stack_a, *ch_size);
	mid = mid_key(restack, *ch_size);
	while (*ch_size > 2 && flag == 0)
	{
		ra += road_top_a2(stack_a, mid, *len_a);
		trick_pb(stack_b, stack_a, len_b, len_a);
		*ch_size -= 1;
		count++;
		if (!chunk_sorted_a(*stack_a, mid, *ch_size))
		{
			back_top_a(*stack_a, ra, *len_a);
			flag = 1;
		}
	}
	if (*ch_size == 2)
		sort_2(*stack_a, *ch_size);
	free(restack);
	return (count);
}

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
