/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alpha_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:49:13 by silndoj           #+#    #+#             */
/*   Updated: 2024/06/07 22:12:06 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_issdigit(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i] && flag == 0)
	{
		if (str[i] >= 48 && str[i] <= 57)
			flag = 0;
		else
			flag = 1;
		i++;
	}
	if (flag == 1)
	{
		ft_printf("Error\n");
		return ;
	}
}

int	ft_alpha_error(char **str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			ft_issdigit(str[i]);
			if (str[i][j] == '+' || str[i][j] == '-')
			{
				if (!(str[i][j + 1] >= 48 && str[i][j + 1] <= 57))
				{
					ft_printf("Error\n");
					return (1);
				}
				j++;
			}
			j++;
		}
		i++;
	}
	return (0);
}
