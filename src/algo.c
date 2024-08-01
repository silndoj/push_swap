/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:52:06 by silndoj           #+#    #+#             */
/*   Updated: 2024/08/01 01:41:47 by silndoj          ###   ########.fr       */
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
	int	a;
	int	chunk;
	int	chunk1;
	int *chunk_arr_b;
	int *chunk_temp;

	i = 0;
	j = 0;
	chunk_temp = push_all_b(stack_a, stack_b, len_a, len_b);
	while (chunk_temp[j + 1] > 0)
		j++;
	chunk_arr_b = malloc(sizeof(int) * j);
	ft_memcpy(chunk_arr_b, chunk_temp, sizeof(int) * j);
	j--;
	free(chunk_temp);
	while (j >= 0)
	{
		if (!chunk_control_b(*stack_b, chunk_arr_b[j]) && chunk_arr_b[j] > 2)
		{
			int l = 0;
			while (l < chunk_arr_b[j])
			{
				trick_pa(stack_a, stack_b, len_a, len_b);
				l++;
			}
			j--;
		}
		if (chunk_arr_b[j] == 1)
		{
			trick_pa(stack_a, stack_b, len_a, len_b);
			chunk_arr_b[j] -= 1;
			j--;
		}
		else if (chunk_arr_b[j] == 2)
		{
			sort_2b(*stack_b, *len_b);
			trick_pa(stack_a, stack_b, len_a, len_b);
			trick_pa(stack_a, stack_b, len_a, len_b);
			chunk_arr_b[j] -= 2;
			j--;
		}
		else if (chunk_arr_b[j] > 2)
		{
			i = 0;
			while (i < chunk_arr_b[j])
			{
				a = (*stack_b)[i];
				i++;
			}
			i = 0;
			chunk = push_a(stack_b, stack_a, &chunk_arr_b[j], len_b, len_a);
			if (chunk == 2)
				sort_2(*stack_a, *len_a);
			else if (chunk > 2)
			{
				if (check_sorted(*stack_a, chunk))
				{
					while (chunk > 2)
					{
						chunk1 = push_b2(stack_a, stack_b, len_a, &chunk, len_b);
						chunk_arr_b = ft_new_chunk(chunk_arr_b, chunk1, j + 1);
						j++;
					}
					chunk_arr_b = ft_new_chunk(chunk_arr_b, 0, j + 1);
					j++;
				}
			}
			j--;
		}
		if (chunk_arr_b[j + 1] > 0)
			j++;
	}
//	ft_printf("len_a = %d\n", *len_a);
//	ft_printf("len_b = %d\n", *len_b);
//	*len_b -= 1;
//	while (*len_b >= 0)
//	{
//		ft_printf("stack_b[%d] = %d\n", *len_b, (*stack_b)[*len_b]);
//		(*len_b)--;
//	}
//	ft_printf("\n\n");
//	*len_a -= 1;
//	while (*len_a >= 0)
//	{
//		ft_printf("stack_a[%d] = %d\n", *len_a, (*stack_a)[*len_a]);
//		(*len_a)--;
//	}
//	ft_printf("\n\n");
//	while (j >= 0)
//	{
//		ft_printf("size of passed chunk[%d] = %d\n", j, chunk_arr_b[j]);
//		j--;
//	}
	free(chunk_arr_b);
}
