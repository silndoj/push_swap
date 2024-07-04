/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:46:42 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/04 17:13:19 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//int	sstack_dv(int *sstack, int smax, int smin)
//{
//	int	pivot;
//	int	i;
//	int	j;
//	int	k;
//	int	flag;
//
//	flag = 1;
//	pivot = sstack[smax];
//	i = (smin - 1);
//	j = smin;
//	k = 0;
//	while (j <= smax - 1)
//	{
//		if (sstack[j] < pivot)
//		{
//			i++;
//			while (flag == 1)
//			{
//				while (k <= smax)
//				{
//					if (sstack[k] == ex_pos)
//						pos = i;
//					i++;
//				}
//				if (pos < len_a / 2)
//				{
//					if (sstack_a[0] != 11)
//						trick_ra(sstack_a, len_a);
//				}
//				if (pos > len_a / 2)
//				{
//					if (sstack_a[0] != 11)
//						trick_rra(sstack_a, len_a);
//				}
//				if (sstack_a[0] == 11)
//					flag = 0;
//			}
//		}
//	}
//}
//
//int	quick_sort(int *sstack_a, int smax, int smin)
//{
//	if (s_min < smax)
//	{
//		int	pi;
//
//		pi = sstack_dv(sstack_a, smin, smax);
//	}
//}

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
	swap_specific(sstack_a, 4, 11, len_a);
//	ft_printf("len_b = %d\n", len_b);
//	while (i < len_b)
//	{
//		ft_printf("stack[%d] = %d\n", i, sstack_b[i]);
//		i++;
//	}
//	ft_printf("\n\n");
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
