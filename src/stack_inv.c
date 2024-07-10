/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_inv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:36:31 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/09 19:48:40 by silndoj          ###   ########.fr       */
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
		i++;
		j++;
	}
	free(temp);
	return (sstack);
}

char	*args_to_single(char **argv, int len)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = 1;
	str = ft_strjoin(argv[i], " ");
	i++;
	while (argv[i])
	{
		str = ft_strjoin(str, argv[i]);
		str = ft_strjoin(str, " ");
		i++;
		j++;
	}
	return (str);
}
//int	*stack_inv(char **sstring_int)
//{
//	int		i;
//	int		j;
//	char	*temp;
//	char	*stack;
//
//	i = 1;
//	j = 0;
//	while (sstring_int[i])
//		i++;
//	i--;
//	temp = malloc(sizeof(char) * i);
//	i = 1;
//	while (sstring_int[i])
//	{
//		temp[j] = ft_atoi(sstring_int[i]);
//		i++;
//		j++;
//	}
//	temp[j] = '\0';
//	sstack_trick(temp);
//	return (stack);
//}
