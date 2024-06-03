/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:43:16 by silndoj           #+#    #+#             */
/*   Updated: 2024/03/11 13:37:26 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
//int main (void)
//{
//	char str[] = "Silvi Ndoj";
//	printf("first is : %s\n", str);
//	ft_bzero(str, 5);
//	printf("second is: %s\n", str);
//	return (0);
//}
