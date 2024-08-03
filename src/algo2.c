/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:07:07 by silndoj           #+#    #+#             */
/*   Updated: 2024/08/03 05:15:10 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	push_a(t_stack *stack_b, t_stack *stack_a, int *ch_size, int j)
{
	int	*restack;
	t_utils util;

	util.r = 0;
	util.flag = 0;
	util.count = 0;
	util.half = *ch_size / 2;
	restack = algo_secret2(stack_b->stack, *ch_size);
	util.mid = mid_key(restack, *ch_size);
	while (*ch_size > util.half && util.flag == 0)
	{
		util.r += road_top_b(&stack_b->stack, util.mid, stack_b->len);
		trick_pa(&stack_a->stack, &stack_b->stack, &stack_a->len, &stack_b->len);
		*ch_size -= 1;
		util.count++;
		if (!chunk_sorted_b(stack_b->stack, util.mid, *ch_size))
		{
			if (j != 0)
				back_top_b(stack_b->stack, util.r, stack_b->len);
			util.flag = 1;
		}
	}
	free(restack);
	return (util.count);
}

int	push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_utils util;
	int	*restack;

	util.flag = 0;
	util.count = 0;
	restack = algo_secret(stack_a->stack, stack_a->len);
	util.mid = mid_key(restack, stack_a->len);
	while (stack_a->len > 2 && util.flag == 0)
	{
		road_top_a(stack_a->stack, util.mid, stack_a->len);
		trick_pb(&stack_b->stack, &stack_a->stack, &stack_b->len, &stack_a->len);
		util.count++;
		if (!chunk_sorted_a(stack_a->stack, util.mid, stack_a->len))
			util.flag = 1;
	}
	free(restack);
	return (util.count);
}

int	push_b2(t_stack *stack_a, t_stack *stack_b, int *ch_size)
{
	t_utils	util;
	int	*restack;

	util.flag = 0;
	util.r = 0;
	util.count = 0;
	restack = algo_secret2(stack_a->stack, *ch_size);
	util.mid = mid_key(restack, *ch_size);
	while (*ch_size > 2 && util.flag == 0)
	{
		util.r += road_top_a2(&stack_a->stack, util.mid, stack_a->len);
		trick_pb(&stack_b->stack, &stack_a->stack, &stack_b->len, &stack_a->len);
		*ch_size -= 1;
		util.count++;
		if (!chunk_sorted_a(stack_a->stack, util.mid, *ch_size))
		{
			back_top_a(stack_a->stack, util.r, stack_a->len);
			util.flag = 1;
		}
	}
	if (*ch_size == 2)
		sort_2(stack_a->stack, stack_a->len);
	free(restack);
	return (util.count);
}

int	*push_all_b(t_stack *stack_a, t_stack *stack_b)
{
	t_utils u;
	int	*chunk_arr_b;
	int	i;

	i = 1;
	chunk_arr_b = malloc(sizeof(int));
	u.chunk = push_b(stack_a, stack_b);
	chunk_arr_b[0] = u.chunk;
	while (stack_a->len > 2)
	{
		u.chunk = push_b(stack_a, stack_b);
		chunk_arr_b = ft_new_chunk(chunk_arr_b, u.chunk, i);
		i++;
	}
	chunk_arr_b = ft_new_chunk(chunk_arr_b, i, i);
	chunk_arr_b = ft_new_chunk(chunk_arr_b, 0, i + 1);
	chunk_arr_b = ft_new_chunk(chunk_arr_b, -1, i + 2);
	sort_2(stack_a->stack, stack_a->len);
	return (chunk_arr_b);
}
