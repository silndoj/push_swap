/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:57:47 by silndoj           #+#    #+#             */
/*   Updated: 2024/03/30 14:28:53 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_count(int nr, int *count)
{
	if (nr == -2147483648)
		ft_putstr_count("-2147483648", count);
	else
	{
		if (nr < 0)
		{
			ft_putchar_count('-', count);
			nr *= -1;
		}
		if (nr >= 0 && nr < 10)
			ft_putchar_count(nr + 48, count);
		if (nr > 9)
		{
			ft_putnbr_count(nr / 10, count);
			ft_putnbr_count(nr % 10, count);
			count++;
		}
	}
}
