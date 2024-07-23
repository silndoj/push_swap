/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:46:42 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/23 21:25:41 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void  algo_union(int **stack_a, int **stack_b, int *len_a, int *len_b)
{
	if (*len_a == 2 && check_sorted(*stack_a, *len_a))
		sort_2(*stack_a, *len_a);
	if (*len_a == 3 && check_sorted(*stack_a, *len_a))
		sort_3(*stack_a, *len_a);
	if (*len_a == 4 && check_sorted(*stack_a, *len_a))
		sort_4(stack_a, stack_b, len_a, len_b);
	if (*len_a == 5 && check_sorted(*stack_a, *len_a))
		sort_5(stack_a, stack_b, len_a, len_b);
	else if (*len_a > 5 && check_sorted(*stack_a, *len_a))
		algo_ultimate(stack_a, stack_b, len_a, len_b);
}

void	sstack_trick(char *argv)
{
	int		*sstack_a;
	int		*sstack_b;
	int		i;
	int		len_a;
	int		len_b;

	i = 0;
	len_a = 0;
	len_b = 0;
	sstack_a = sstack_inv(argv, &len_a);
	sstack_b = malloc(sizeof(int) * 1);
//	sstack_a = ft_minus_stack(sstack_a, len_a);
//	trick_rra(sstack_a, len_a);
	algo_union(&sstack_a, &sstack_b, &len_a, &len_b);
//	while (i < len_a)
//	{
//		ft_printf("stack_a[%d] = %d\n",i ,sstack_a[i]);
//		i++;
//	}
//	i = 0;
//	ft_printf("\n");
//	while (i < len_b)
//	{
//		ft_printf("stack_b[%d] = %d\n",i ,sstack_b[i]);
//		i++;
//	}
	free(sstack_a);
	free(sstack_b);
}
