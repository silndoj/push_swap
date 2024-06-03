/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:45:26 by silndoj           #+#    #+#             */
/*   Updated: 2024/03/11 19:54:24 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_toupper(int c)
{
	if ((c >= 97) && (c <= 122))
		return (c - 32);
	else
		return (c);
}
//
//int main()
//{
//	int c;
//	int c1;
//
//	c = 122;
//	printf("c = %c\n",c);
//	c1 = ft_toupper(c);
//	printf("c/1 = %c\n", c1);
//}
