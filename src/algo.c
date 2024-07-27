/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:52:06 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/28 00:36:46 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	*algo_secret(int *stack, int len)
{
	int	i;
	int	temp;
	int	*ustack;

	i = 0;
	ustack = malloc(sizeof(int) * len);
	ft_memcpy(ustack, stack, sizeof(int) * len);
	while (i < len - 1)
	{
		if (ustack[i] > ustack[i + 1])
		{
			temp = ustack[i];
			ustack[i] = ustack[i + 1];
			ustack[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	return (ustack);
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
	mid = mid_key(restack, *len_a);
	while (*len_a >= 2 && flag == 0)
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

int	push_b2(int **stack_a, int **stack_b, int ch_size, int *len_b)
{
	int	flag;
	int ra;
	int	count;
	int	mid;
	int	*restack;

	flag = 0;
	count = 0;
	restack = algo_secret(*stack_a, ch_size);
	mid = mid_key(restack, ch_size);
	while (ch_size >= 2 && flag == 0)
	{
		ra = road_top_a2(*stack_a, mid, ch_size);
		trick_pb(stack_b, stack_a, len_b, &ch_size);
		back_top_a(*stack_a, ra, ch_size);
		count++;
		if (!chunk_sorted_a(*stack_a, mid, ch_size))
			flag = 1;
	}
	free(restack);
	return (count);
}

int	push_a(int **stack_b, int **stack_a, int ch_size, int *len_a)
{
	int	half;
	int	flag;
	int rb;
	int	count;
	int	mid;
	int	*restack;

	half = ch_size / 2;
	flag = 0;
	count = 0;
	restack = algo_secret(*stack_b, ch_size);
	mid = mid_key(restack, ch_size);
	while (ch_size > half && flag == 0)
	{
		rb = road_top_b(*stack_b, mid, ch_size);
		trick_pa(stack_a, stack_b, len_a, &ch_size);
		back_top_b(*stack_b, rb, ch_size);
		count++;
		if (!chunk_sorted_b(*stack_b, mid, ch_size))
			flag = 1;
	}
	free(restack);
	return (count);
}

void  algo_ultimate(int **stack_a, int **stack_b, int *len_a, int *len_b)
{
	int	j;
	int i;
	int	chunk;
	int	chunk1;
	int *chunk_arr_b;

	j = 0;
	chunk_arr_b = push_all_b(stack_a, stack_b, len_a, len_b);
	while (chunk_arr_b[j + 1] > 0)
		j++;
	j--;
	while (j >= 0)
	{
		if (chunk_arr_b[j] == 1)
		{
			trick_pa(stack_a, stack_b, len_a, len_b);
			j--;
		}
		else if (chunk_arr_b[j] == 2)
		{
			sort_2b(*stack_b, *len_b);
			trick_pa(stack_a, stack_b, len_a, len_b);
			trick_pa(stack_a, stack_b, len_a, len_b);
			j--;
		}
		else if (chunk_arr_b[j] > 2)
		{
			chunk = push_a(stack_b, stack_a, chunk_arr_b[j], len_a);
			chunk1 = push_b2(stack_a, stack_b, chunk, len_b);
			j++;
			chunk_arr_b = ft_new_chunk(chunk_arr_b, chunk1, j);
		}
	}


	ft_printf("size of last chunk = %d\n", chunk);
	while (j >= 0)
	{
		ft_printf("size of passed chunk[%d] = %d\n", j, chunk_arr_b[j]);
		j--;
	}
	free(chunk_arr_b);
}
