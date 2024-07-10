/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alpha_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:49:13 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/10 00:37:19 by silndoj          ###   ########.fr       */
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

int	ft_double(char *needle, char **str, int pos)
{
	int	i;

	i = 0;
	if (needle[0] == '+')
		needle = ft_strtrim(needle, "+");
	while (str[i])
	{
		if (i == pos && str[i + 1])
			i++;
		else if (str[i + 1])
		{
			if (str[i][0] == '+')
				str[i] = ft_strtrim(str[i], "+");
			if (ft_atoi(str[i]) == ft_atoi(needle))
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_error_single(char *str)
{
	char	**temp;
	int		i;

	i = 0;
	temp = ft_split(str, ' ');
	while (temp[i])
	{
		if (ft_sign(temp[i])
			|| ft_double(temp[i], temp, i)
			|| ft_atoi2(temp[i]) > INT_MAX
			|| ft_atoi2(temp[i]) < INT_MIN)
		{
			ft_printf("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}
