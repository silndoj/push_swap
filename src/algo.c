/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:52:06 by silndoj           #+#    #+#             */
/*   Updated: 2024/08/03 05:17:10 by silndoj          ###   ########.fr       */
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

void	push_a_back_b(t_stack *stack_a, t_stack *stack_b, t_utils *u)
{
	int	i;
	u->chunk = push_a(stack_b, stack_a, &u->chunk_arr[u->r], u->r);
	if (u->chunk == 2)
		sort_2(stack_a->stack, stack_a->len);
	else if (u->chunk > 2)
	{
		if (check_sorted(stack_a->stack, u->chunk))
		{
			while (u->chunk > 2)
			{
				u->chunk1 = push_b2(stack_a, stack_b, &u->chunk);
				u->chunk_arr = ft_new_chunk(u->chunk_arr, u->chunk1, u->r + 1);
				u->r++;
			}
			u->chunk_arr = ft_new_chunk(u->chunk_arr, 0, u->r + 1);
			u->r++;
		}
	}
	u->r--;
}

void	push_all_a(t_stack *stack_a, t_stack *stack_b, t_utils *u)
{
	while (u->r >= 0)
	{
		if (u->chunk_arr[u->r] == 1)
		{
			trick_pa(&stack_a->stack, &stack_b->stack, &stack_a->len, &stack_b->len);
			u->chunk_arr[u->r] -= 1;
			u->r--;
		}
		else if (u->chunk_arr[u->r] == 2)
		{
			sort_2b(stack_b);
			trick_pa(&stack_a->stack, &stack_b->stack, &stack_a->len, &stack_b->len);
			trick_pa(&stack_a->stack, &stack_b->stack, &stack_a->len, &stack_b->len);
			u->chunk_arr[u->r] -= 2;
			u->r--;
		}
		else if (u->chunk_arr[u->r] > 2)
			push_a_back_b(stack_a, stack_b, u);
		if (u->chunk_arr[u->r + 1] > 0)
			u->r++;
	}
	free(u->chunk_arr);
}

void	algo_ultimate(t_stack *stack_a, t_stack *stack_b)
{
	int		*chunk_temp;
	t_utils	*u;


	u = malloc(sizeof(t_utils));
	u->r = 0;
	chunk_temp = push_all_b(stack_a, stack_b);
	while (chunk_temp[u->r + 1] > 0)
		u->r++;
	u->chunk_arr = malloc(sizeof(int) * u->r);
	ft_memcpy(u->chunk_arr, chunk_temp, sizeof(int) * u->r);
	u->r--;
	free(chunk_temp);
	push_all_a(stack_a, stack_b, u);
	free(u);
}
