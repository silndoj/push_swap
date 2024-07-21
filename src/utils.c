/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:59:23 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/21 22:52:52 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


int	*ft_memcpy_int(int *dest, int *src, int n)
{
	int	i;

	i = 0;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	return (dest);
}

int	*ft_realloc_int(void *src, size_t size)
{
	int	*new_src;
	
	new_src = (int *) malloc(sizeof(int) * size);
	new_src = ft_memcpy_int(new_src, src, size);
	free(src);
	src = new_src;
	return (src);
}

int	*algo_secret2(int *stack, int *dest, int len)
{
	int	i;
	int	temp;
	int	*ustack;

	i = 0;
	free(dest);
	ustack = stack_copy(stack, len);
	while (i < len)
	{
		if (ustack[i] > ustack[i + 1])
		{
			temp = ustack[i];
			ustack[i] = ustack[i + 1];
			ustack[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	dest = stack_copy(ustack, len);
	free(ustack);
	ustack = NULL;
	return (dest);
}
