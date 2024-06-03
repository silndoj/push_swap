/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:36:25 by silndoj           #+#    #+#             */
/*   Updated: 2024/03/30 18:56:37 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	format_c(const char *s, int *count, va_list args)
{
	if (*s == 'c')
		ft_putchar_count(va_arg(args, int), count);
	else if (*s == 's')
		ft_putstr_count(va_arg(args, char *), count);
	else if (*s == 'p')
	{
		ft_putstr_count("0x", count);
		ft_ptr_count(va_arg(args, unsigned long), count);
	}
	else if (*s == 'd' || *s == 'i')
		ft_putnbr_count(va_arg(args, int), count);
	else if (*s == 'u')
		ft_unsigned_int(va_arg(args, unsigned int), count);
	else if (*s == 'x')
		ft_x(va_arg(args, unsigned int), count);
	else if (*s == 'X')
		ft_up_x(va_arg(args, unsigned int), count);
	else if (*s == '%')
		ft_putchar_count('%', count);
	else
	{
		write(1, s, 1);
		count++;
	}
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, s);
	if (!s)
		return (-1);
	while (*s)
	{
		if (*s != '%')
		{
			write(1, s++, 1);
			count++;
		}
		if (*s == '%')
		{
			format_c(++s, &count, args);
			s++;
		}
	}
	va_end(args);
	return (count);
}
//#include <limits.h>
//int main ()
//{
//	int c = 299;
//
//	ft_printf("check = > %c", c);
//	printf("\ncheck = > %c\n", c);
//	ft_printf("%X", UINT_MAX);
//	printf("\n%X", UINT_MAX);
//}
