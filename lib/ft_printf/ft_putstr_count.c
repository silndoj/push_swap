/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:47:41 by silndoj           #+#    #+#             */
/*   Updated: 2024/03/30 18:57:06 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_count(char *ptr, int *count)
{
	size_t	i;

	i = 0;
	if (!ptr)
		ptr = "(null)\0";
	while (ptr[i])
		i++;
	write(1, ptr, i);
	*count += i;
}
