/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:49:52 by silndoj           #+#    #+#             */
/*   Updated: 2024/06/12 18:56:08 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char *argv[])
{
	char		**temp;
	int			a;
	int			i;
	int			j;

	a = 1;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc >= 2)
	{
		while (a < argc)
		{
			temp = ft_split(argv[a], ' ');
			if (ft_error(temp))
				return (1);
			
			a++;
		}
	}
	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j + 2])
		{
			if (j == i)
				j++;
			if (!double_trouble(argv[i], argv[j]))
			{
				ft_printf("Error\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}
