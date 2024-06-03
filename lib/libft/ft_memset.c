/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:02:45 by silndoj           #+#    #+#             */
/*   Updated: 2024/03/12 14:14:17 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (len > 0)
	{
		*((unsigned char *)(b + i)) = (unsigned char) c;
		i++;
		len--;
	}
	return (b);
}
//
//int main(void)
//{
//	char str[] = "silvi ndoj";
//	printf("here is : %s\n", str);
//	ft_memset(str + 3, '0', 5);
//	printf("answer is : %s\n",str);
//}
