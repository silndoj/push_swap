/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_inv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:36:31 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/21 21:25:47 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	*sstack_inv(char *string_int, int *len_a)
{
	int		i;
	int		j;
	int		*sstack;
	char	**temp;

	j = 0;
	i = 0;
	temp = ft_split(string_int, ' ');
	while (temp[i])
		i++;
	sstack = malloc(sizeof(int) * i);
	*len_a = i - 1;
	i = 0;
	while (temp[i])
	{
		sstack[j] = ft_atoi(temp[i]);
		free(temp[i]);
		temp[i] = NULL;
		i++;
		j++;
	}
	free(temp);
	temp = NULL;
	return (sstack);
}

char	*ft_strjoin2(char *s1, char *md, char *s2)
{
	char	*ptr;
	int		s1len;
	int		s2len;
	int		midlen;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	midlen = ft_strlen(md);
	ptr = malloc((s1len + s2len + midlen + 1) * sizeof(char));
	if (!ptr)
		return (0);
	ft_memcpy(ptr, s1, s1len);
	ft_memcpy((ptr + s1len), md, midlen);
	ft_memcpy((ptr + s1len + midlen), s2, s2len);
	ptr[s1len + s2len + midlen + 1] = '\0';
	free(s1);
	return (ptr);
}

char	*ft_strdup2(char *s1)
{
	char	*t1;
	size_t	slen;

	slen = ft_strlen(s1);
	t1 = malloc((slen + 1) * sizeof(char));
	if (!t1)
		return (0);
	ft_memcpy(t1, s1, slen);
	t1[slen + 1] = '\0';
	free(s1);
	return (t1);
}

char	*args_to_single(char **argv)
{
	int		i;
	int		j;
	char	*str;
	char	*temp;

	j = 0;
	i = 1;
	temp = ft_strjoin(argv[i], " ");
	i++;
	while (argv[i])
	{
		str = ft_strjoin(temp, argv[i]);
		free(temp);
		if (argv[i + 1])
		{
			temp = ft_strdup(str);
			free(str);
			str = ft_strjoin(temp, " ");
			free(temp);
			temp = ft_strdup(str);
			free(str);
		}
		i++;
		j++;
	}
	return (str);
}

//char	*args_to_single(char **argv)
//{
//	int		i;
//	char	*str;
//	char	*temp;
//
//	i = 2;
//	temp = ft_strdup(argv[1]);
//	while (argv[i])
//	{
//		str = NULL;
//		str = ft_strjoin2(temp, " ", argv[i]);
//		temp = NULL;
//		if (argv[i + 1])
//			temp = ft_strdup2(str);
//		else 
//			i++;
//		i++;
//	}
//	return (str);
//}
