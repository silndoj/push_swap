/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:46:42 by silndoj           #+#    #+#             */
/*   Updated: 2024/08/04 11:43:15 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	algo_union(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->len == 2)
		sort_2(stack_a->stack, stack_a->len);
	if (stack_a->len == 3)
		sort_3(stack_a->stack, stack_a->len);
	if (stack_a->len == 4)
		sort_4(&stack_a->stack, &stack_b->stack, &stack_a->len, &stack_b->len);
	if (stack_a->len == 5)
		sort_5(&stack_a->stack, &stack_b->stack, &stack_a->len, &stack_b->len);
	else if (stack_a->len > 5)
		algo_ultimate(stack_a, stack_b);
}

void	sstack_trick(char *argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	stack_a->len = 0;
	stack_b->len = 0;
	stack_a->stack = sstack_inv(argv, &stack_a->len);
	stack_b->stack = malloc(sizeof(int) * 1);
	if (check_sorted(stack_a->stack, stack_a->len))
		algo_union(stack_a, stack_b);
	free(stack_a->stack);
	free(stack_b->stack);
	free(stack_a);
	free(stack_b);
}
