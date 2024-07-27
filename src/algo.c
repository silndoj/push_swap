/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:52:06 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/27 22:12:52 by silndoj          ###   ########.fr       */
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
	int	j;
	int i;
	int	chunk;
	int *chunk_arr_b;

	j = 0;
	chunk_arr_b = push_all_b(stack_a, stack_b, len_a, len_b);
	while (chunk_arr_b[j + 1] > 0)
		j++;
	j--;
	chunk = push_big_a(stack_a, stack_b, len_a, len_b);
	ft_printf("size of last chunk = %d\n", chunk);
	while (j >= 0)
	{
		ft_printf("size of passed chunk[%d] = %d\n", j, chunk_arr_b[j]);
		j--;
	}
	free(chunk_arr_b);
}
