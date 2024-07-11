/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:46:42 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/11 03:55:47 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sstack_trick(char *argv)
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
	sstack_b = malloc(sizeof(int) * len_a);
	algorithm_100(sstack_a, sstack_b, &len_a, &len_b);
//	while (i <= len_a)
//	{
//		ft_printf("stack_a[%d] = %d\n",i ,sstack_a[i]);
//		i++;
//	}
	free(sstack_a);
	free(sstack_b);
	sstack_a = NULL;
	sstack_b = NULL;
}
