/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:59:47 by silndoj           #+#    #+#             */
/*   Updated: 2024/06/18 23:33:15 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*s2;
	size_t	end;
	size_t	start;
	size_t	newlen;

	start = 0;
	end = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && (ft_strchr(set, s1[start])))
		start++;
	while ((end > start) && (ft_strchr(set, s1[end - 1])))
		end--;
	newlen = end - start;
	s2 = (char *) ft_calloc(newlen + 1, sizeof(char));
	if (!s2)
		return (NULL);
	ft_memcpy(s2, s1 + start, newlen);
	return (s2);
}
//
//int main ()
//{
//	char	s1[100] = "+-silvi";
//	char	*res;
//
//	res = ft_strtrim(s1, "+-");
//	printf("result :%s\n", res);
//}
