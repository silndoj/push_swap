/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alpha_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:49:13 by silndoj           #+#    #+#             */
/*   Updated: 2024/06/12 18:49:32 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_issdigit(char str)
{
	int	flag;

	flag = 0;
	if (str >= 48 && str <= 57)
		flag = 0;
	else
		flag = 1;
	return (flag);
}

int	ft_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			i++;
			if (ft_issdigit(str[i]))
				return (1);
		}
		else if (ft_issdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	double_trouble(char *str, char *reject)
{
	int i;
	int	flag;

	i = 0;
	flag = 0;
	while(reject[i] && flag == 0)
	{
		if (str[i] != reject[i])
			return (1);
		i++;
	}
	return (flag);
}

int	ft_error(char **str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (ft_sign(str[i]))
		{
			ft_printf("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}
