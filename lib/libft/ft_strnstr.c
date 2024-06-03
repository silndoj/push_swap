/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:46:07 by silndoj           #+#    #+#             */
/*   Updated: 2024/03/13 17:20:16 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == 0)
		return ((char *) haystack);
	while (i < len && haystack[i] != '\0')
	{
		while ((haystack[j + i] != '\0') && (haystack[i + j] == needle[j])
			&& (i + j < len))
		{
			j++;
			if (needle[j] == 0)
				return ((char *) haystack + i);
		}
		i++;
		j = 0;
	}
	return (0);
}
//
//int main()
//{
//	const char *s1 = "ndoj silvi";
//	const char *p = "silvi";
//	const char *result, *result1;
//
//	result = ft_strnstr(s1, p, 9);
//	result1 = strnstr(s1, p, 9);
//	printf("result : %s\nresult1 : %s\n",result, result1);
//}
