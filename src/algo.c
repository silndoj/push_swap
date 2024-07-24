/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:52:06 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/24 18:24:53 by silndoj          ###   ########.fr       */
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

int	push_a(int **stack_b, int **stack_a, int *len_b, int *len_a)
{
	int	flag;
	int	count;
	int	mid;
	int	*restack;

	flag = 0;
	count = 0;
	restack = algo_secret(*stack_b, *len_b);
	mid = mid_key(restack, *len_b);
	while (*len_b >= 0 && flag == 0)
	{
		road_top_b(*stack_b, mid, *len_b);
		trick_pa(stack_a, stack_b, len_a, len_b);
		count++;
		if (!chunk_sorted_b(*stack_b, mid, *len_b))
			flag = 1;
	}
	return (count);
}

void  algo_ultimate(int **stack_a, int **stack_b, int *len_a, int *len_b)
{
	int	i;
	int	j;
	int	chunk;
	int *chunk_arr_b;
//	int	*chunk_arr_a;

	i = 1;
	chunk_arr_b = malloc(sizeof(int) * 1);
//	chunk_arr_a = malloc(sizeof(int) * 1);
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
	if (!chunk_control_b(*stack_b, chunk_arr_b[i]))
	{
		chunk = chunk_arr_b[i];
		while (chunk >= 0)
		{
			trick_pa(stack_a, stack_b, len_a, len_b);
			chunk--;
		}
	}
//	j = 1;
//	while (*len_b >= 1)
//	{
//		while (chunk_arr_b[i] >= 0)
//		{
//			if (!chunk_control_b(*stack_b, chunk_arr_b[i]))
//			{
//				chunk = chunk_arr_b[i];
//				while (chunk >= 0)
//				{
//					trick_pa(stack_a, stack_b, len_a, len_b);
//					chunk--;
//				}
//			}
//			else if (sizeof(chunk_arr_a) == 1)
//			{
//				chunk = push_a(stack_b, stack_a, &chunk_arr_b[i], len_a);
//				chunk_arr_a[0] = chunk;
//			}
//			else
//			{
//				chunk = push_a(stack_b, stack_a, &chunk_arr_b[i], len_a);
//				chunk_arr_a = ft_new_chunk(chunk_arr_a, chunk, j);
//				j++;
//			}
//			i--;
//		}
//	}
	j = 0;
	while (j < i)
	{
		ft_printf("size of passed chunk[%d] = %d\n", j, chunk_arr_b[j]);
		j++;
	}
	free(chunk_arr_b);
}
