/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 21:55:46 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/11 03:03:08 by silndoj          ###   ########.fr       */
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
int		ft_error_single(char *str);
int		ft_double(char *needle, char **str, int i);
long	ft_atoi2(const char *str);

//Stack_Creator_Functions
char	*args_to_single(char **argv, int len);
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
void	sstack_trick(char *argv);

//Algorithms
void	sort_2(int *stack, int len_a);
void	sort_3(int *stack, int len_a);
void	sort_4(int *stack_a, int *stack_b, int *len_a, int *len_b);
void	sort_5(int *stack_a, int *stack_b, int *len_a, int *len_b);
void	algorithm_100(int *stack_a, int *stack_b, int *len_a, int *len_b);
void	alg_basic_a(int *stack_a, int *stack_b, int *len_a, int *len_b);
void	alg_basic_b(int *stack_b, int *stack_a, int *len_b, int *len_a);
void	push_chunk(int *stack_a, int *stack_b, int *len_a, int *len_b);
int		*algo_secret(int *stack_a, int len_a);

//Utils
int		check_sorted(int *stack_a, int len_a);
int		*stack_copy(int *stack, int slen);
int		get_key(int *stack, int len, int chunk_nr);
void	road_top_a(int *stack_a, int pos, int len_a);
void	road_top_b(int *stack_a, int pos, int len_a);

#endif
