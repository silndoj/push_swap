/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 21:55:46 by silndoj           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/06/29 06:29:15 by silndoj          ###   ########.fr       */
=======
/*   Updated: 2024/07/03 04:26:44 by silndoj          ###   ########.fr       */
>>>>>>> 34cbd41a01f5b679e379727702a9967d0f91e08f
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include <limits.h>

//Error_Functions
int		ft_issdigit(char str);
int		ft_sign(char *str);
int		ft_error(char **str);
int		ft_error_single(char *str);
int		ft_double(char *needle, char **str, int i);
long	ft_atoi2(const char *str);

//Stack_Creator_Functions
int		*stack_inv(char **sstring_int);
int		*sstack_inv(char *string_int);
int		stack_trick(char **argv, int len_a);
int		sstack_trick(char *argv);

//Stack_A_Options_Functions
int		trick_sa(int *stack_a, int len_a);
void	trick_pa(int *stack_a, int *stack_b, int *len_a, int *len_b);
void	trick_ra(int *stack_a, int len_a);
void	trick_rra(int *stack_a, int len_a);

//Stack_B_Options_Functions
<<<<<<< HEAD
int		trick_sb(int *stack_a, int len_a);
int		trick_pb(int *stack_b, int *stack_a, int len_b, int len_a);
int		trick_rb(int *stack_b, int len_b);
int		trick_rrb(int *stack_b, int len_b);
=======
int		trick_sb(int *stack_b, int len_b);
void	trick_pb(int *stack_b, int *stack_a, int *len_b, int *len_a);
void	trick_rb(int *stack_b, int len_b);
void	trick_rrb(int *stack_b, int len_b);
>>>>>>> 34cbd41a01f5b679e379727702a9967d0f91e08f

//Both_Stacks_Options_Functions
int		trick_ss(int *stack_a, int *stack_b, int len_a, int len_b);
void	trick_rr(int *stack_a, int *stack_b, int len_a, int len_b);
void	trick_rrr(int *stack_a, int *stack_b, int len_a, int len_b);

//Shifts_Options
void	shift_up(int *stack, int *len);
void	shift_down(int *stack, int *len);

#endif
