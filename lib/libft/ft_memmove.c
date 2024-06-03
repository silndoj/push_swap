/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:13:54 by silndoj           #+#    #+#             */
/*   Updated: 2024/05/27 17:54:24 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	else if (dest > src)
	{
		while (len-- > 0)
		{
			*((unsigned char *)(dest + len)) = *((unsigned char *)(src + len));
		}
	}
	else
	{
		while (i < len)
		{
			*((unsigned char *)(dest + i)) = *((unsigned char *)(src + i));
			i++;
		}
	}
	return (dest);
}
//
//int main()
//{
//	char src[10] = "123456789";
//	printf("first is : %s\n", src);
//	char dest[10] = "123456789";
//	ft_memmove(dest, src, 4);
//	printf("second is : %s\n", src);
//}
