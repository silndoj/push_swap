/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:13:54 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/07 23:27:25 by silndoj          ###   ########.fr       */
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
//	int src[5] = {1, 2, 3, 4, 5};
//	int	*dest;
//	dest = NULL;
//	ft_memmove(dest, src, 4);
//	printf("second is : %d\n", dest[1]);
//}
