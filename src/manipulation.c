/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:46:42 by silndoj           #+#    #+#             */
/*   Updated: 2024/06/28 19:09:09 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	*sstack_inv(char *argv)
{
	int		i;
	int		j;
	int		*sstack;
	char	**temp;

	j = 0;
	i = 0;
	temp = ft_split(argv, ' ');
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

int	*stack_inv(char **argv)
{
	int	i;
	int	j;
	int	*stack;

	i = 1;
	j = 0;
	while (argv[i])
		i++;
	stack = malloc(sizeof(int) * i);
	i = 1;
	while (argv[i])
	{
		stack[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	return (stack);
}

void	sstack_trick(char *argv)
{
	int	*stack_a;
	int	i;

	i = 0;
	stack_a = sstack_inv(argv);
	while (i < 5)
	{
		ft_printf("stack[%d] = %d\n", i, stack_a[i]);
		i++;
	}
}

void	stack_trick(char **argv)
{
	int	*stack_a;
	int	i;

	i = 0;
	stack_a = stack_inv(argv);
	while (i < 5)
	{
		ft_printf("stack[%d] = %d\n", i, stack_a[i]);
		i++;
	}
}
