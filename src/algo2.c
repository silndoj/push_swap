/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:07:07 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/28 00:35:56 by silndoj          ###   ########.fr       */
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
		rra_road(&stack_a, mid, &len_a, &flag);
		ra_road(&stack_a, mid, &len_a, &flag);
	}
}

int	*push_all_b(int **stack_a, int **stack_b, int *len_a, int *len_b)
{
	int	*chunk_arr_b;
	int chunk;
	int	i;

	i = 1;
	chunk_arr_b = malloc(sizeof(int));
	chunk = push_b(stack_a, stack_b, len_a, len_b);
	chunk_arr_b[0] = chunk;
	while (*len_a > 2)
	{
		chunk = push_b(stack_a, stack_b, len_a, len_b);
		chunk_arr_b = ft_new_chunk(chunk_arr_b, chunk, i);
		i++;
	}
	chunk_arr_b = ft_new_chunk(chunk_arr_b, i, i);
	chunk_arr_b = ft_new_chunk(chunk_arr_b, 0, i + 1);
	chunk_arr_b = ft_new_chunk(chunk_arr_b, -1, i + 2);
	sort_2(*stack_a, *len_a);
	return (chunk_arr_b);
}

int	road_b_top(int **stack_b, int mid, int len_b)
{
	int	flag;
	int	temp;
	int b;

	b = 0;
	flag = 0;
	temp = (*stack_b)[mid];
	while (flag == 0)
	{
		if ((*stack_b)[0] == temp)
			flag = 1;
		while (flag == 0 && mid >= (len_b / 2))
		{
			trick_rrb(*stack_b, len_b);
			b++;
			if ((*stack_b)[0] == temp)
			{
				flag = 1;
				b *= -1;
			}
		}
		if (b == 0)
		{
			while (flag == 0 && mid < (len_b / 2))
			{
				trick_rb(*stack_b, len_b);
				b++;
				if ((*stack_b)[0] == temp)
					flag = 1;
			}
		}
	}
	return (b);
}

void	road_top_a(int *stack_a, int mid, int len_a)
{
	int	flag;
	int	i;

	i = 0;
	flag = 0;
	while (flag == 0)
	{
		if (stack_a[0] < mid)
			flag = 1;
		if (stack_a[len_a] < mid && flag == 0)
		{
			trick_rra(stack_a, len_a);
			flag = 1;
		}
		else if (flag == 0)
			ra_top(&stack_a, mid, &len_a, &flag);
	}
}

int	road_top_a2(int *stack_a, int mid, int len_a)
{
	int	flag;
	int	i;
	int a;

	a = 0;
	i = 0;
	flag = 0;
	while (flag == 0)
	{
		if (stack_a[0] < mid)
			flag = 1;
		if (stack_a[len_a] < mid && flag == 0)
		{
			trick_rra(stack_a, len_a);
			flag = 1;
		}
		else if (flag == 0)
			a = ra_top(&stack_a, mid, &len_a, &flag);
	}
	return (a);
}

int	road_top_b(int *stack_b, int mid, int len_b)
{
	int	flag;
	int	b;

	b = 0;
	flag = 0;
	while (flag == 0)
	{
		if (stack_b[0] > mid)
			flag = 1;
		if(stack_b[len_b] > mid && flag == 0)
			rrb_top(&stack_b, mid, &len_b, &flag);
		else if (flag == 0)
			b = rb_top(&stack_b, mid, &len_b, &flag);
	}
	return (b);
}
