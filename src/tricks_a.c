/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricks_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:31:45 by silndoj           #+#    #+#             */
/*   Updated: 2024/06/28 20:54:19 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	trick_sa(int *stack_a, int len_a)
{
	int	temp;

	if (len_a <= 2)
		return (1);
	temp = stack_a[1];
	stack_a[1] = stack_a[2];
	stack_a[2] = temp;
	ft_printf("sa\n");

	return (0);
}
