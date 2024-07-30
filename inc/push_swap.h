/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 21:55:46 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/30 02:26:28 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include <limits.h>

//Core_Functions
void	sstack_trick(char *argv);

//Error_Functions
int		ft_issdigit(char str);
int		ft_sign(char *str);
int		ft_error_single(char *str);
int		ft_double(char *needle, char **str, int i);
long	ft_atoi2(const char *str);

//Stack_Creator_Functions
int		*sstack_inv(char *string_int, int *len_a);
char	*ft_strjoin2(char *s1, char *md, char *s2);
char	*ft_strdup2(char *s1);
char	*args_to_single(char **argv);

//Stack_A_Options_Functions
void	trick_sa(int *stack_a, int len_a);
void	trick_pa(int **stack_a, int **stack_b, int *len_a, int *len_b);
void	trick_ra(int *stack_a, int len_a);
void	trick_rra(int *stack_a, int len_a);

//Stack_B_Options_Functions
void	trick_sb(int *stack_b, int len_b);
void	trick_pb(int **stack_b, int **stack_a, int *len_b, int *len_a);
void	trick_rb(int *stack_b, int len_b);
void	trick_rrb(int *stack_b, int len_b);

//Both_Stacks_Options_Functions
void	trick_ss(int *stack_a, int *stack_b, int len_a, int len_b);
void	trick_rr(int *stack_a, int *stack_b, int len_a, int len_b);
void	trick_rrr(int *stack_a, int *stack_b, int len_a, int len_b);

//Algorithms
void	sort_2b(int *stack_b, int len_b);
void	sort_2(int *stack, int len_a);
void	sort_3(int *stack, int len_a);
void	sort_4(int **stack_a, int **stack_b, int *len_a, int *len_b);
void	sort_5(int **stack_a, int **stack_b, int *len_a, int *len_b);
void	algo_ultimate(int **stack_a, int **stack_b, int *len_a, int *len_b);
void	algo_union(int **stack_a, int **stack_b, int *len_a, int *len_b);
int		push_big_a(int **stack_a, int **stack_b, int *len_a, int *len_b);
int		*push_all_b(int **stack_a, int **stack_b, int *len_a, int *len_b);
int		push_b(int **stack_a, int **stack_b, int *len_a, int *len_b);
int		push_b2(int **stack_a, int **stack_b, int *len_a, int *ch_size, int *len_b);
int		push_a(int **stack_b, int **stack_a, int *ch_size, int *len_b, int *len_a);
int		*algo_secret2(int *stack, int len);
int		*algo_secret(int *stack, int len);

//Utils_Algo
int		road_b_top(int **stack_b, int mid, int len_b);
void	back_top_b(int *stack_b, int b, int len_b);
void	back_top_a(int *stack_a, int a, int len_a);
void	rra_road(int **stack_a, int mid, int *len_a, int *flag);
void	ra_road(int **stack_a, int mid, int *len_a, int *flag);
void	road_a_top(int *stack_a, int mid, int len_a);
//-
int		ra_top(int **stack_a, int mid, int *len_a, int *flag);
int		ra_top1(int ***stack_a, int mid, int *len_a, int *flag);
int		rb_top(int ***stack_b, int mid, int *len_b, int *flag);
int		rrb_top(int **stack_b, int mid, int *len_b, int *flag);
int		road_top_a2(int **stack_a, int mid, int len_a);
void	road_top_a(int *stack_a, int mid, int len_a);
int		road_top_b(int **stack_b, int mid, int len_b);
//-
int		check_sorted(int *stack, int len);
int		chunk_control_b(int	*stack_b, int chunk_len);
int		chunk_sorted_a(int *stack, int mid, int len);
int		chunk_sorted_b(int *stack, int mid, int len);

//Utils
int		mid_key(int *stack, int len);
int		*ft_new_chunk(int *src, int chunk, int size);
int		*ft_minus_stack(int	*stack, int len);
int		*ft_plus_stack(int	*stack, int len);

#endif
