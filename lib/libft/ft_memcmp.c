/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:19:28 by silndoj           #+#    #+#             */
/*   Updated: 2024/03/13 12:45:14 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char *) s1;
	st2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char) st1[i] != (unsigned char) st2[i])
			return ((unsigned char) st1[i] - (unsigned char) st2[i]);
		i++;
	}
	return (0);
}
//
//int main ()
//{
//	char s1[10] = "silvi";
//	char s2[10] = "silci";
//
//	char result = ft_memcmp(s1, s2, 4);
//	char result1 = memcmp(s1, s2, 4);
//
//	printf("result ft_memcp(): %d\nresult memcmp(): %d\n", result, result1);
//}
