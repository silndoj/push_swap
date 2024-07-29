/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:59:23 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/29 18:24:20 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	mid_key(int *stack, int len)
{
	int	key;

	key = stack[(len - 1) / 2];
	return (key);
}

int	*ft_new_chunk(int *src, int chunk, int size)
{
	int	*new_src;
	int newlen;

	newlen = size;
	new_src = malloc(sizeof(int) * (newlen + 1));
	ft_memcpy(new_src, src, sizeof(int) * newlen);
	free(src);
	new_src[newlen] = chunk;
	return (new_src);
}

int	*ft_plus_stack(int *stack, int len)
{
	int	*new_src;

	new_src = malloc(sizeof(int) * (len + 1));
	ft_memcpy(new_src + 1, stack, sizeof(int) * len);
	free(stack);
	return (new_src);
}

int	*ft_minus_stack(int	*stack, int len)
{
	int	*new_src;

	new_src = malloc(sizeof(int) * len);
	ft_memcpy(new_src, stack + 1, sizeof(int) * (len - 1));
	free(stack);
	return (new_src);
}
