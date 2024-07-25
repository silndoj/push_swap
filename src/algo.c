/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:52:06 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/25 02:05:18 by silndoj          ###   ########.fr       */
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

int	push_a(int **stack_b, int **stack_a, int *ch_len, int *len_a)
{
	int	flag;
	int	count;
	int	mid;
	int top;
	int	*restack;

	top = 0;
	flag = 0;
	count = 0;
	restack = algo_secret(*stack_b, *ch_len);
	mid = mid_key(restack, *ch_len);
	while (ch_len > 2 && flag == 0)
	{
		top = road_top_b(*stack_b, mid, *ch_len);
		trick_pa(stack_a, stack_b, len_a, ch_len);
		count++;
		if (!chunk_sorted_b(*stack_b, mid, *ch_len))
			flag = 1;
	}
	if (top < 0)
	{
		top = -1;
		while (top > 0)
			trick_rrb(*stack_b, *ch_len);
	}
	else
	{
		while (top > 0)
			trick_rb(*stack_b, *ch_len);
	}
	return (count);
}

void  algo_ultimate(int **stack_a, int **stack_b, int *len_a, int *len_b)
{
	int	i;
	int	j;
	int	chunk;
	int	chunk_a;
	int *chunk_arr_b;

	i = 1;
	chunk_arr_b = malloc(sizeof(int) * 1);
	chunk = push_b(stack_a, stack_b, len_a, len_b);
	chunk_arr_b[0] = chunk;
	while (*len_a > 2)
	{
		chunk = push_b(stack_a, stack_b, len_a, len_b);
		chunk_arr_b = ft_new_chunk(chunk_arr_b, chunk, i);
		i++;
	}
	sort_2(*stack_a, *len_a);
	i--;
//	j = 1;
	while (*len_b >= 2)
	{
		while (chunk_arr_b[i] >= 0)
		{
			if (!chunk_control_b(*stack_b, chunk_arr_b[i]))
			{
				while (chunk_arr_b >= 0)
				{
					trick_pa(stack_a, stack_b, len_a, len_b);
					chunk_arr_b[i]--;
				}
			}
			else
			{
				chunk_a = push_a(stack_b, stack_a, &chunk_arr_b[i], len_a);
				*len_b -= chunk_a;
				if (chunk_a == 2)
					sort_2(*stack_a, *len_a);
				if (chunk_a > 2)
				{
					chunk = push_b(stack_a, stack_b, &chunk_a, len_b);
					sort_2(*stack_a, chunk_a);
					chunk_arr_b = ft_new_chunk(chunk_arr_b, chunk, i);
					i += 2;
				}
			}
			i--;
		}
	}
	sort_2(*stack_b, *len_b);
	trick_pa(stack_a, stack_b, len_a, len_b);
	trick_pa(stack_a, stack_b, len_a, len_b);
//	j = 0;
//	while (j < i)
//	{
//		ft_printf("size of passed chunk[%d] = %d\n", j, chunk_arr_b[j]);
//		j++;
//	}
	free(chunk_arr_b);
}
