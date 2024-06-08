/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alpha_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:49:13 by silndoj           #+#    #+#             */
/*   Updated: 2024/06/08 17:20:14 by silndoj          ###   ########.fr       */
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

int	ft_double(char *s1, char *s2)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (s1[i])
	{
		if (s2[i] == s1[i])
			flag = 1;
		else
			flag = 0;
		i++;
	}
	return (flag);
}

int	ft_error(char **str)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (str[i])
	{
		if (ft_sign(str[i]))
		{
			ft_printf("Error\n");
			return (1);
		}
		temp = str[i];
		j = 0;
		while (str[j])
		{
			if (ft_double(str[j], temp))
			{
				ft_printf("Error\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
