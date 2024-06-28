/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:12:30 by silndoj           #+#    #+#             */
/*   Updated: 2024/06/27 17:27:41 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long	ft_atoi2(const char *str)
{
	int		i;
	int		n;
	long	result;

	n = 1;
	i = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	else if (str[i] == '-')
	{
		n *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (str[i] - '0') + (result * 10);
		i++;
	}
	return (result * n);
}
//
//int main()
//{
//	int result, result1;
//	result = atoi(" 99999999999999999999999999999999");
//	printf("result atoi: %d\n", result);
//	result1 = ft_atoi("  99999999999999999999999999999999");
//	printf("result ft_atoi: %d\n", result1);
//}
