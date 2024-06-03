/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:48:33 by silndoj           #+#    #+#             */
/*   Updated: 2024/03/30 18:46:14 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ptr_count(unsigned long ptr, int *count)
{
	if (ptr >= 16)
		ft_ptr_count(ptr / 16, count);
	ptr %= 16;
	if (ptr > 9 && ptr < 16)
	{
		if (ptr == 10)
			ft_putchar_count('a', count);
		if (ptr == 11)
			ft_putchar_count('b', count);
		if (ptr == 12)
			ft_putchar_count('c', count);
		if (ptr == 13)
			ft_putchar_count('d', count);
		if (ptr == 14)
			ft_putchar_count('e', count);
		if (ptr == 15)
			ft_putchar_count('f', count);
	}
	if (ptr <= 9)
		ft_putchar_count(ptr + 48, count);
	count++;
}
