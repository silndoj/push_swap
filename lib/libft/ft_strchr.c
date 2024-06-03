/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 20:07:51 by silndoj           #+#    #+#             */
/*   Updated: 2024/04/16 20:03:24 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == (char) c)
		return ((char *) &s[i]);
	return (0);
}
//
//int main ()
//{
//	char *result1;
//	char *result;
//	char s[10] = "papakalo";
//	
//
//	result1 = strchr(s, 'a');
//	result = ft_strchr(s, 'a');
//	printf("result = %s\n", result);
//	printf("result1 = %s\n", result1);
//}
