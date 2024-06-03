/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:54:46 by silndoj           #+#    #+#             */
/*   Updated: 2024/05/27 17:56:25 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_tolower(int c)
{
	if ((c >= 65) && (c <= 90))
		return (c + 32);
	else
		return (c);
}
//
//int main()
//{
//	int c;
//	int c1;
//	
//	c = 66;
//	c1 = ft_tolower(c);
//	printf("c = %c\n", c);
//	printf("c1 = %c\n", c1);
//}
