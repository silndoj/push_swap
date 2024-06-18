/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 20:52:25 by silndoj           #+#    #+#             */
/*   Updated: 2024/06/18 15:16:19 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && n > 0)
	{
		if ((unsigned char) *s1 != (unsigned char) *s2)
			return ((unsigned char) *s1 - (unsigned char) *s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
//
//int main()
//{
//	char s1[10] = "998";
//	char s2[10] = "998";
//	
//	char  result = ft_strncmp(s1, s2, 3);
//	printf("result : %d\n", result);
//}
//
