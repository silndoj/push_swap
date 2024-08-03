/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:07:07 by silndoj           #+#    #+#             */
/*   Updated: 2024/08/03 08:20:43 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	push_a(t_stack *b, t_stack *a, int *ch_size, int j)
{
	int		*restack;
	t_utils	util;

	util.r = 0;
	util.flag = 0;
	util.count = 0;
	util.half = *ch_size / 2;
	restack = algo_secret2(b->stack, *ch_size);
	util.mid = mid_key(restack, *ch_size);
	while (*ch_size > util.half && util.flag == 0)
	{
		util.r += road_top_b(&b->stack, util.mid, b->len);
		trick_pa(&a->stack, &b->stack, &a->len, &b->len);
		*ch_size -= 1;
		util.count++;
		if (!chunk_sorted_b(b->stack, util.mid, *ch_size))
		{
			if (j != 0)
				back_top_b(b->stack, util.r, b->len);
			util.flag = 1;
		}
	}
	free(restack);
	return (util.count);
}

int	push_b(t_stack *a, t_stack *b)
{
	int		*restack;
	t_utils	util;

	util.flag = 0;
	util.count = 0;
	restack = algo_secret(a->stack, a->len);
	util.mid = mid_key(restack, a->len);
	while (a->len > 2 && util.flag == 0)
	{
		road_top_a(a->stack, util.mid, a->len);
		trick_pb(&b->stack, &a->stack, &b->len, &a->len);
		util.count++;
		if (!chunk_sorted_a(a->stack, util.mid, a->len))
			util.flag = 1;
	}
	free(restack);
	return (util.count);
}

int	push_b2(t_stack *a, t_stack *b, int *ch_size)
{
	int		*restack;
	t_utils	util;

	util.flag = 0;
	util.r = 0;
	util.count = 0;
	restack = algo_secret2(a->stack, *ch_size);
	util.mid = mid_key(restack, *ch_size);
	while (*ch_size > 2 && util.flag == 0)
	{
		util.r += road_top_a2(&a->stack, util.mid, a->len);
		trick_pb(&b->stack, &a->stack, &b->len, &a->len);
		*ch_size -= 1;
		util.count++;
		if (!chunk_sorted_a(a->stack, util.mid, *ch_size))
		{
			back_top_a(a->stack, util.r, a->len);
			util.flag = 1;
		}
	}
	if (*ch_size == 2)
		sort_2(a->stack, a->len);
	free(restack);
	return (util.count);
}

int	*push_all_b(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		*chunk_arr_b;
	t_utils	u;

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
