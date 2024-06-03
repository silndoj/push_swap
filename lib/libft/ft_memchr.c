/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:14:51 by silndoj           #+#    #+#             */
/*   Updated: 2024/03/18 00:13:47 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	size_t			i;

	i = 0;
	s1 = (unsigned char *) s;
	while (i < n)
	{
		if (s1[i] == (unsigned char) c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
//
//int main()
//{
//	char s1[10] = "cecilia";
//	char *result;
//
//	result = ft_memchr(s1, 'i', 6);
//	printf("result :  %s\n", result);
//}
