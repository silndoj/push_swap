/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:59:23 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/22 21:45:45 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	*ft_new_chunk(int *src, int chunk, int size)
{
	int	*new_src;
	int newlen;

	newlen = size + 1;
	new_src = malloc(sizeof(int) * newlen);
	ft_memcpy(new_src, src, sizeof(int) * newlen);
	free(src);
	new_src[newlen] = chunk;
//	src = malloc(sizeof(int) * size);
//	ft_memcpy(src, new_src, sizeof(int) * size);
//	free(new_src);
	return (new_src);
}
