/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 20:37:27 by silndoj           #+#    #+#             */
/*   Updated: 2024/03/14 12:18:01 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*flag;

	flag = NULL;
	while (*s)
	{
		if (*s == (char) c)
			flag = (char *) s;
		s++;
	}
	if (*s == (char) c)
		flag = (char *) s;
	if (!(flag == 0))
		return (flag);
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
//	result1 = strrchr(s, 'a');
//	result = ft_strrchr(s, 'a');
//	printf("result = %s\n", result);
//	printf("result1 = %s\n", result1);
//}
