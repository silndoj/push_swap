/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:49:52 by silndoj           #+#    #+#             */
/*   Updated: 2024/06/09 00:51:05 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char *argv[])
{
	char	**temp;
	int		a;

	a = 1;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc >= 2)
	{
		while (a < argc)
		{
			temp = ft_split(argv[a], ' ');
			if (!ft_error(temp))
				a++;
			else
				return (1);
		}
	}
	return (0);
}
//j = 0;
//			while (temp[i])
//			{
//				if (j != i)
//				{
//					if (!ft_double(str[j], str[i]))
//					{
//						ft_printf("Error\n");
//						return (1);
//					}
//				}
//				j++;
//			}
