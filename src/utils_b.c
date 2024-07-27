/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:01:45 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/28 00:15:52 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/push_swap.h"

void sort_2b(int *stack_b, int len_b)
{
	if (stack_b[0] < stack_b[1])
		trick_sb(stack_b, len_b);
}

void	back_top_b(int *stack_b, int b, int len_b)
{
	while (b > 0)
	{
		trick_rrb(stack_b, len_b);
		b--;
	}
}

void	back_top_a(int *stack_a, int a, int len_a)
{
	while (a > 0)
	{
		trick_rra(stack_a, len_a);
		a--;
	}
}

int	push_big_a(int **stack_a, int **stack_b, int *len_a, int *len_b)
{
	int	i;
	int b;
	int	half;
	int	pos;
	int	restack;

	pos = 0;
	half = *len_b / 2;
	while (*len_b >= half)
	{
		i = 0;
		restack = (*stack_b)[0];
		while (i <= half)
		{
			if (restack < ((*stack_b)[i]))
			{
				restack = ((*stack_b)[i]);
				pos = i;
			}
			i++;
		}
		b = road_b_top(stack_b, pos, *len_b);
		trick_pa(stack_a, stack_b, len_a, len_b);
		back_top_b(*stack_b, b, *len_b);
	}
	return (half);
}

//	while (i >= 0 && flag == 0)
//	{
//		if (!chunk_control_b(*stack_b, chunk_arr_b[i]))
//		{
//			chunk = chunk_arr_b[i];
//			while (chunk > 0)
//			{
//				trick_pa(stack_a, stack_b, len_a, len_b);
//				chunk--;
//			}
//			i--;
//		}
//		ft_printf("next chunk b%d = [%d]\n",i ,chunk_arr_b[i]);
//		if (chunk_arr_b[i] > 2)
//		{
//			chunk = push_a(stack_b, stack_a, &chunk_arr_b[i], len_a);
//			if (chunk > 2)
//			{
//				while (chunk > 2)
//				{
//					chunk1 = push_b(stack_a, stack_b, &chunk, len_b);
//					chunk_arr_b = ft_new_chunk(chunk_arr_b, chunk1, i);
//					i++;
//				}
//				i--;
//				sort_2(*stack_a, *len_a);
//			}
//		}
//		if (chunk_arr_b[i] == 2)
//		{
//			sort_2b(*stack_b, *len_b);
//			trick_pa(stack_a, stack_b, len_a, len_b);
//			trick_pa(stack_a, stack_b, len_a, len_b);
//			chunk_arr_b[i] -= 2;
//			i--;
//		}
//		flag = 1;
//	}
