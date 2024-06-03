/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:22:50 by silndoj           #+#    #+#             */
/*   Updated: 2024/03/13 18:15:07 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		n;
	int		result;

	n = 1;
	i = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
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
//	result = atoi("  -54222h");
//	printf("result atoi: %d\n", result);
//	result1 = ft_atoi("  -54222h");
//	printf("result ft_atoi: %d\n", result1);
//}
