/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 21:55:46 by silndoj           #+#    #+#             */
/*   Updated: 2024/06/28 18:58:55 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include <limits.h>

//typedef struct s_core
//{
//	int				data;
//	struct s_core	*next;
//}				t_core;

int		ft_issdigit(char str);
int		ft_sign(char *str);
int		ft_error(char **str);
int		ft_error_single(char *str);
int		ft_double(char *needle, char **str, int i);
long	ft_atoi2(const char *str);
int		*stack_inv(char **argv);
int		*sstack_inv(char *argv);
void	stack_trick(char **argv);
void	sstack_trick(char *argv);

#endif
