/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:46:42 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/01 04:18:29 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
	i--;
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
	i--;
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

int	sstack_trick(char *argv)
{
	int		*sstack_a;
	int		*sstack_b;
	int		i;
	int		len_a;
//	int		len_b;
	char	**temp;

	i = 0;
	len_a = 0;
	temp = ft_split(argv, ' ');
	while (temp[len_a])
		len_a++;
	sstack_a = sstack_inv(argv);
	sstack_b = sstack_inv(argv);
	//trick_pa(sstack_a, sstack_b, len_a);
	trick_sa(sstack_a, len_a);
//	trick_ra(sstack_a, len_a);
//	trick_pb(sstack_b, sstack_a,)
	trick_rra(sstack_a, len_a);
		while (i <= len_a)
		{
			ft_printf("stack[%d] = %d\n", i, sstack_a[i]);
			i++;
		}
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
