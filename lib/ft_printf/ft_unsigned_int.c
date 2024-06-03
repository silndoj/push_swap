/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:13:10 by silndoj           #+#    #+#             */
/*   Updated: 2024/03/30 14:10:26 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned_int(unsigned int i, int *count)
{
	if (i >= 10)
		ft_unsigned_int(i / 10, count);
	ft_putchar_count(i % 10 + '0', count);
	count++;
}
