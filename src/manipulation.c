/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:46:42 by silndoj           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/06/29 07:09:33 by silndoj          ###   ########.fr       */
=======
/*   Updated: 2024/07/03 20:24:48 by silndoj          ###   ########.fr       */
>>>>>>> 34cbd41a01f5b679e379727702a9967d0f91e08f
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

<<<<<<< HEAD
int	*sstack_inv(char *string_int)
{
	int		i;
	int		j;
	int		*sstack;
	char	**temp;

	j = 0;
	i = 0;
	temp = ft_split(string_int, ' ');
	while (temp[i])
		i++;
	sstack = malloc(sizeof(int) * i);
	i = 0;
	while (temp[i])
	{
		sstack[j] = ft_atoi(temp[i]);
		i++;
		j++;
	}
	return (sstack);
}

int	*stack_inv(char **sstring_int)
{
	int	i;
	int	j;
	int	*stack;

	i = 1;
	j = 0;
	while (sstring_int[i])
		i++;
	stack = malloc(sizeof(int) * i);
	i = 1;
	while (sstring_int[i])
	{
		stack[j] = ft_atoi(sstring_int[i]);
		i++;
		j++;
	}
	return (stack);
}

=======
>>>>>>> 34cbd41a01f5b679e379727702a9967d0f91e08f
int	sstack_trick(char *argv)
{
	int		*stack_a;
	int		i;
	int		len_a;
<<<<<<< HEAD
=======
	int		len_b;
>>>>>>> 34cbd41a01f5b679e379727702a9967d0f91e08f
	char	**temp;
//	int		b[1];

	i = 0;
	len_a = 0;
<<<<<<< HEAD
//	b[0] = 8;
	temp = ft_split(argv, ' ');
	while (temp[len_a])
		len_a++;
	stack_a = sstack_inv(argv);
	if (trick_rra(stack_a, len_a))
		return (1);
	while (i < 3)
	{
		ft_printf("stack[%d] = %d\n", i, stack_a[i]);
=======
	len_b = 0;
	temp = ft_split(argv, ' ');
	while (temp[len_a])
		len_a++;
	sstack_a = sstack_inv(argv);
	sstack_b = sstack_inv(argv);
	ft_printf("len_b = %d\n", len_b);
	while (i < len_b)
	{
		ft_printf("stack[%d] = %d\n", i, sstack_b[i]);
		i++;
	}
	i = 0;
	ft_printf("\n\n");
	ft_printf("len_a = %d\n", len_a);
	while (i < len_a)
	{
		ft_printf("stack[%d] = %d\n", i, sstack_a[i]);
>>>>>>> 34cbd41a01f5b679e379727702a9967d0f91e08f
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
