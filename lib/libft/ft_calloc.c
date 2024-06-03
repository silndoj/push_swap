/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:19:43 by silndoj           #+#    #+#             */
/*   Updated: 2024/03/14 13:01:03 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, (count * size));
	return (ptr);
}
//
//int main ()
//{
//	unsigned char *ptr, *ptr1;
//
//	ptr1 = calloc(42 * 3, sizeof(char));
//	ptr = ft_calloc(42 * 3, sizeof(char));
//	printf("result is: %d\nresult2 is: %d\n", (int) ptr, (int) ptr1);
//	free (ptr1);
//	free (ptr);
//}
