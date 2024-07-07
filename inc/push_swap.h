/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 21:55:46 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/07 07:19:55 by silndoj          ###   ########.fr       */
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
int		*sstack_inv(char *string_int, int *len_a);

//Stack_A_Options_Functions
void	trick_sa(int *stack_a, int len_a);
void	trick_pa(int *stack_a, int *stack_b, int *len_a, int *len_b);
void	trick_ra(int *stack_a, int len_a);
void	trick_rra(int *stack_a, int len_a);

//Stack_B_Options_Functions
void	trick_sb(int *stack_b, int len_b);
void	trick_pb(int *stack_b, int *stack_a, int *len_b, int *len_a);
void	trick_rb(int *stack_b, int len_b);
void	trick_rrb(int *stack_b, int len_b);

//Both_Stacks_Options_Functions
void	trick_ss(int *stack_a, int *stack_b, int len_a, int len_b);
void	trick_rr(int *stack_a, int *stack_b, int len_a, int len_b);
void	trick_rrr(int *stack_a, int *stack_b, int len_a, int len_b);

//Shifts_Options
void	shift_up(int *stack, int *len);
void	shift_down(int *stack, int *len);

//Core_Functions
int		*stack_trick(char **argv, int len_a);
int		*sstack_trick(char *argv);

//Algorithms
void	sort_2(int *stack, int len_a);
void	sort_3(int *stack, int len_a);
void	sort_4(int *stack_a, int *stack_b, int *len_a, int *len_b);
void	sort_5(int *stack_a, int *stack_b, int *len_a, int *len_b);
int		algo_secret(int *stack_a, int len_a);
void	algorithm_1(int *stack_a, int *stack_b, int *len_a, int *len_b);
void	algorithm_2(int *stack_a, int *stack_b, int *len_a, int *len_b);

//Algorithm_Utils
void	push_all_a(int *stack_a, int *stack_b, int *len_a, int *len_b);
void	road_top(int *stack_a, int pos, int len_a);

#endif
