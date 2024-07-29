/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:52:06 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/29 18:19:17 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	*algo_secret2(int *stack, int len)
{
	int	i;
	int	temp;
	int	*ustack;

	i = 0;
	ustack = malloc(sizeof(int) * len);
	ft_memcpy(ustack, stack, sizeof(int) * (len + 1));
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

void  algo_ultimate(int **stack_a, int **stack_b, int *len_a, int *len_b)
{
	int	j;
	int i;
	int	chunk;
	int	chunk1;
	int *chunk_arr_b;
	int *chunk_temp;

	i = 0;
	j = 0;
	chunk_arr_b = push_all_b(stack_a, stack_b, len_a, len_b);
	while (chunk_arr_b[j + 1] > 0)
		j++;
	j--;
	chunk_temp = malloc(sizeof(int) * j);
	ft_memcpy(chunk_temp, chunk_arr_b, sizeof(int) * (j + 1));
	ft_printf("last chunk = %d\n", chunk_arr_b[j]);
	ft_printf("last chunk = %d\n", chunk_temp[j]);
//	while (j >= 0)
//	{
//		
//		if (chunk_arr_b[j] == 1)
//		{
//			trick_pa(stack_a, stack_b, len_a, &chunk_arr_b[j]);
//			j--;
//		}
//		else if (chunk_arr_b[j] == 2)
//		{
//			sort_2b(*stack_b, *len_b);
//			trick_pa(stack_a, stack_b, len_a, &chunk_arr_b[j]);
//			trick_pa(stack_a, stack_b, len_a, &chunk_arr_b[j]);
//			j--;
//		}
//		else if (chunk_arr_b[j] > 2)
//		{
//			chunk = push_a(stack_b, stack_a, &chunk_arr_b[j], len_a);
//			if (chunk == 2)
//				sort_2(*stack_a, *len_a);
//			else if (chunk > 2)
//			{
//				while (chunk > 2)
//				{
//					j++;
//					chunk1 = push_b2(stack_a, stack_b, chunk, &chunk_arr_b[j]);
//					chunk_arr_b = ft_new_chunk(chunk_arr_b, chunk1, j);
//				}
//			}
//			j--;
//		}
//		i = chunk_arr_b[j + 1];
//		if (chunk_arr_b[j + 1] > 0)
//			j++;
//	}
	ft_printf("len_a = %d\n", *len_a);
	ft_printf("len_b = %d\n", *len_b);
	while (j >= 0)
	{
		ft_printf("size of passed chunk[%d] = %d\n", j, chunk_arr_b[j]);
		j--;
	}
	free(chunk_arr_b);
}
