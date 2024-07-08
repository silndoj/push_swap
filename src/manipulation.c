/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:46:42 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/08 20:38:03 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sstack_trick(char *argv)
{
	int		*sstack_a;
	int		*sstack_b;
	int		len_a;
	int		len_b;
	int		i;

	i = 0;
	len_a = 0;
	len_b = -1;
	sstack_a = sstack_inv(argv, &len_a);
	sstack_b = malloc(sizeof(int) * len_a);
//	sort_5(sstack_a, sstack_b, &len_a, &len_b);
	algorithm_100(sstack_a, sstack_b, &len_a, &len_b);
	while (i <= len_a)
	{
		ft_printf("stack_a[%d] = %d\n",i ,sstack_a[i]);
		i++;
	}
	free(sstack_a);
	free(sstack_b);
}

void	stack_trick(char **argv, int len_a)
{
	int	*stack_a;
	int	*stack_b;
	int	len_b;
	int	i;

	len_b = -1;
	i = 0;
	stack_a = stack_inv(argv);
	stack_b = malloc(sizeof(int) * len_a);
//	sort_5(stack_a, stack_b, &len_a, &len_b);
	algorithm_100(stack_a, stack_b, &len_a, &len_b);
//	while (i <= len_a)
//	{
//		ft_printf("stack_a[%d] = %d\n",i ,stack_a[i]);
//		i++;
//	}
	free(stack_a);
	free(stack_b);
}
