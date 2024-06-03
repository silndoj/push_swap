/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:59:50 by silndoj           #+#    #+#             */
/*   Updated: 2024/04/03 03:18:05 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_substr(char c, char dm)
{
	if (c == dm)
		return (1);
	return (0);
}

static int	c_words(const char *s, char c)
{
	int	words;

	words = 0;
	while (*s)
	{
		while (*s && c_substr(*s, c))
			s++;
		if (*s)
			words++;
		while (*s && !c_substr(*s, c))
			s++;
	}
	return (words);
}

static char	*fill_w(const char *ptr, char c)
{
	int		i;
	char	*s1;

	i = 0;
	s1 = 0;
	while (ptr[i] && ptr[i] != c)
		i++;
	s1 = (char *) ft_calloc((i + 1), sizeof(char));
	if (!s1)
		return (NULL);
	ft_memcpy(s1, ptr, i);
	return (s1);
}

static void	*ft_free(char **s1, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(s1[j++]);
	free(s1);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**s1;
	char	*mini;

	i = 0;
	if (!s)
		return (NULL);
	s1 = ft_calloc((c_words(s, c)) + 1, sizeof(char *));
	if (!s1)
		return (NULL);
	while (*s)
	{
		while (*s && c_substr(*s, c))
			s++;
		if (*s)
		{
			mini = fill_w(s, c);
			if (!mini)
				return (ft_free(s1, i));
			s1[i++] = mini;
		}
		while (*s && !c_substr(*s, c))
			s++;
	}
	return (s1);
}
//
//int main ()
//{
//	char	s[100] = "projectvis goodv pleasurev";
//	char	**res;
//	res = ft_split(s, 'v');
//	while (*res)
//	{
//		printf("The sentence: %s\nThe Splited: %s\n", s, *res);
//		res++;
//	}
//}
