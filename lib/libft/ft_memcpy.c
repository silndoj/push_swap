/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:07:00 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/20 17:33:48 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		*((char *) (dest + i)) = *((char *) (src + i));
		i++;
	}
	return (dest);
}
//
//int main()
//{
//	int src[5] = {3, 2, 4, 5, 6};
//	printf("src is : %d\n",src[2]);
//	int dest[100];
//	ft_memcpy(dest, src, 4);
//	printf("dest is : %d\n", dest[2]);
//}
