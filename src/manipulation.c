/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:46:42 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/06 01:01:42 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


int	sstack_trick(char *argv)
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
	sstack_b = malloc(len_a);
//	trick_ra(sstack_a, len_a);
//	trick_pb(sstack_b, sstack_a, &len_b, &len_a);
//	sort_3(sstack_a, len_a);
	sort_5(sstack_a, sstack_b, &len_a, &len_b);
	ft_printf("len_b = %d\n", len_b);
	while (i < len_b)
	{
		ft_printf("stack[%d] = %d\n", i, sstack_b[i]);
		i++;
	}
	i = 0;
	ft_printf("\n\n");
	ft_printf("len_a = %d\n", len_a);
	while (i <= len_a)
	{
		ft_printf("stack[%d] = %d\n", i, sstack_a[i]);
		i++;
	}
	return (0);
}

int	stack_trick(char **argv, int len_a)
{
	int	*stack_a;
	int	i;

	i = 0;
	stack_a = stack_inv(argv);
	while (i <= len_a)
	{
		ft_printf("stack[%d] = %d\n", i, stack_a[i]);
		i++;
	}
	return (0);
}
