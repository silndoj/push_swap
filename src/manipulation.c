/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:46:42 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/06 17:20:43 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	*sstack_trick(char *argv)
{
	int		*sstack_a;
	int		*sstack_b;
	int		i;
	int		len_a;
	int		len_b;

	i = 0;
	len_a = 0;
	len_b = -1;
	sstack_a = sstack_inv(argv, &len_a);
	sstack_b = malloc(len_a);
	algorithm_2(sstack_a, sstack_b, &len_a, &len_b);
	return (sstack_a);
}

int	*stack_trick(char **argv, int len_a)
{
	int	*stack_a;
	int	*stack_b;
	int	i;
	int	len_b;

	i = 0;
	len_b = -1;
	stack_a = stack_inv(argv);
	stack_b = malloc(len_a);
	algorithm_2(stack_a, stack_b, &len_a, &len_b);
	return (stack_a);
}
