/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:52:06 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/21 22:55:54 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	road_a_top(int *stack_a, int mid, int len_a)
{
	int	flag;
	int	temp;

	flag = 0;
	temp = stack_a[mid];
	while (flag == 0)
	{
		if (stack_a[0] == temp)
			flag = 1;
		while (flag == 0 && mid >= (len_a / 2) + 1)
		{
			trick_rra(stack_a, len_a);
			if (stack_a[0] == temp)
				flag = 1;
		}
		while (flag == 0 && mid < (len_a / 2) + 1)
		{
			trick_ra(stack_a, len_a);
			if (stack_a[0] == temp)
				flag = 1;
		}
	}
}

int	push_b(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	int	flag;
	int	count;
	int	mid;
	int	*restack;
	int	i;

	flag = 0;
	count = 0;
	restack = algo_secret(stack_a, *len_a);
	while (i <= *len_a)
	{
		ft_printf("stack[%d] = %d\n", i, restack[i]);
		i++;
	}
	mid = mid_key(restack, *len_a);
	while (*len_a >= 2 && flag == 0)
	{
		road_top_a(stack_a, mid, *len_a);
		trick_pb(stack_b, stack_a, len_b, len_a);
		count++;
		if (!chunk_sorted_a(stack_a, mid, *len_a))
			flag = 1;
	}
	free(restack);
	return (count);
}

void  algo_ultimate(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	int	i;
	int j;
	int	chunk;
	int *chunk_arr_b;

	i = 1;
	j = 0;
	chunk_arr_b = (int *) malloc(sizeof(int) * i);
	while (*len_a > 2)
	{
		if (i > 1)
			chunk_arr_b = ft_realloc_int(chunk_arr_b, i);
		chunk = push_b(stack_a, stack_b, len_a, len_b);
		chunk_arr_b[j] = chunk;
		i++;
		j++;
	}
	i--;
	j = 0;
	sort_2(stack_a, *len_a);
	trick_pa(stack_a, stack_b, len_a, len_b);
	while (j < i)
	{
		ft_printf("size of passed chunk[%d] = %d\n", j, chunk_arr_b[j]);
		j++;
	}
	free(chunk_arr_b);
}
