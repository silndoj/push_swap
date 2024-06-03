/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:41:54 by silndoj           #+#    #+#             */
/*   Updated: 2024/03/30 18:41:48 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_up_x(unsigned int x, int *count)
{
	if (x >= 16)
		ft_up_x(x / 16, count);
	x %= 16;
	if (x > 9 && x < 16)
	{
		if (x == 10)
			ft_putchar_count('A', count);
		if (x == 11)
			ft_putchar_count('B', count);
		if (x == 12)
			ft_putchar_count('C', count);
		if (x == 13)
			ft_putchar_count('D', count);
		if (x == 14)
			ft_putchar_count('E', count);
		if (x == 15)
			ft_putchar_count('F', count);
	}
	if (x <= 9)
		ft_putchar_count(x + 48, count);
	count++;
}
