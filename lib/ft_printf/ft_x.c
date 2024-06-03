/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:16:57 by silndoj           #+#    #+#             */
/*   Updated: 2024/03/30 18:41:35 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_x(unsigned int x, int *count)
{
	if (x >= 16)
		ft_x(x / 16, count);
	x %= 16;
	if (x > 9 && x < 16)
	{
		if (x == 10)
			ft_putchar_count('a', count);
		if (x == 11)
			ft_putchar_count('b', count);
		if (x == 12)
			ft_putchar_count('c', count);
		if (x == 13)
			ft_putchar_count('d', count);
		if (x == 14)
			ft_putchar_count('e', count);
		if (x == 15)
			ft_putchar_count('f', count);
	}
	if (x <= 9)
		ft_putchar_count(x + 48, count);
	count++;
}
