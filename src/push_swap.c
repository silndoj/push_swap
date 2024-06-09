/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:49:52 by silndoj           #+#    #+#             */
/*   Updated: 2024/06/09 21:15:23 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char *argv[])
{
	static char	**argv2;
	char		**temp;
	int			a;

	a = 1;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc >= 2)
	{
		while (a < argc)
		{
			temp = ft_split(argv[a], ' ');
			if (!ft_error(temp))
			{
				arg_taker(temp, argv2);
				a++;
			}
			else
				return (1);
		}
	}
	int i;
	i = 0;
	ft_printf("\n\n----------------------------------\n\n");
	while (argv2[i])
	{
		ft_printf("%s\n", argv2[i]);
		i++;
	}
	return (0);
}
