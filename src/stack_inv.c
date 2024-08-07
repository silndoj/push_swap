/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_inv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:36:31 by silndoj           #+#    #+#             */
/*   Updated: 2024/08/03 08:36:38 by silndoj          ###   ########.fr       */
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
	*len_a = i;
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

char	*args_to_single(char **argv)
{
	int		i;
	char	*str;
	char	*temp;

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
	}
	return (str);
}
