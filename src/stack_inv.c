/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_inv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:36:31 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/17 20:35:34 by silndoj          ###   ########.fr       */
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
		temp = ft_strdup(str);
		str = ft_strjoin(temp, " ");
		free(temp);
		temp = ft_strdup(str);
		i++;
		j++;
	}
	free(temp);
	return (str);
}
