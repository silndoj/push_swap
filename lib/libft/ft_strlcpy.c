/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:43:09 by silndoj           #+#    #+#             */
/*   Updated: 2024/03/15 10:55:43 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;

	srcsize = ft_strlen(src);
	if (dstsize > (srcsize + 1))
	{
		ft_memcpy(dst, src, (srcsize + 1));
	}
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, (dstsize - 1));
		dst[dstsize - 1] = '\0';
	}
	return (srcsize);
}
//
//int main()
//{
//	char s1[10] = "Silvi";
//	char s2[10];
//
//	int result;
//	result = ft_strlcpy(s2, s1, 3);
//	printf("result is : %d\n", result);
//	printf("s2 : %s\n", s2);
//	return (0);
//}
