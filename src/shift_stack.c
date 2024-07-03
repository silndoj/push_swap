/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:05:45 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/03 03:26:38 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	shift_up(int *stack, int *len)
{
	int	i;

	i = 0;
	while (i <= *len)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	*len -= 1;
}

void	shift_down(int *stack, int *len)
{
	int	i;
	int	t1;
	int	t2;

	i = 0;
	*len += 1;
	while (i <= *len)
	{
		if (i == 0)
		{
			t1 = stack[i];
			stack[i] = stack[i];
		}
		else if (i != 0)
		{
			t2 = stack[i];
			stack[i] = t1;
			t1 = t2;
		}
		i++;
	}
}
