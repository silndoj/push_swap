/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:37:30 by silndoj           #+#    #+#             */
/*   Updated: 2024/03/30 18:41:25 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

void		ft_putchar_count(char c, int *count);
void		ft_putstr_count(char *ptr, int *count);
void		ft_putnbr_count(int nr, int *count);
void		ft_ptr_count(unsigned long ptr, int *count);
void		ft_x(unsigned int x, int *count);
void		ft_up_x(unsigned int x, int *count);
void		ft_unsigned_int(unsigned int i, int *count);
int			ft_printf(const char *s, ...);

#endif
