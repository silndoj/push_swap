/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricks_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:31:45 by silndoj           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/06/29 07:11:15 by silndoj          ###   ########.fr       */
=======
/*   Updated: 2024/07/03 04:26:02 by silndoj          ###   ########.fr       */
>>>>>>> 34cbd41a01f5b679e379727702a9967d0f91e08f
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	trick_sa(int *stack_a, int len_a)
{
	int	temp;

	if (len_a < 2)
		return (1);
	temp = stack_a[1];
	stack_a[1] = stack_a[2];
	stack_a[2] = temp;
	ft_printf("sa\n");

	return (0);
}

void	trick_pa(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
<<<<<<< HEAD
	int	i;

	i = len_a;
	if (!stack_b[0])
		return (1);
	while (i >= 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = stack_b[0];
	ft_printf("pa\n");

	return (0);
=======
	if (*len_b >= 0)
	{
		shift_down(stack_a, len_a);
		stack_a[0] = stack_b[0];
		shift_up(stack_b, len_b);
		ft_printf("pa\n");
	}
>>>>>>> 34cbd41a01f5b679e379727702a9967d0f91e08f
}

void	trick_ra(int *stack_a, int len_a)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack_a[i];
	while (i < len_a)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[len_a - 1] = temp;
	ft_printf("ra\n");
<<<<<<< HEAD

	return (0);

=======
>>>>>>> 34cbd41a01f5b679e379727702a9967d0f91e08f
}

void	trick_rra(int *stack_a, int len_a)
{
	int	i;
	int	temp;

	i = len_a;
<<<<<<< HEAD
	temp = stack_a[len_a - 1];
=======
	temp = stack_a[i];
>>>>>>> 34cbd41a01f5b679e379727702a9967d0f91e08f
	while (i >= 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = temp;
	ft_printf("rra\n");
<<<<<<< HEAD

	return (0);
=======
>>>>>>> 34cbd41a01f5b679e379727702a9967d0f91e08f
}
