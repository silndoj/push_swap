/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:49:52 by silndoj           #+#    #+#             */
/*   Updated: 2024/06/28 21:16:39 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char *argv[])
{
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		if (ft_error_single(argv[1]))
			return (1);
		if (sstack_trick(argv[1]))
			return (1);
	}
	else if (argc > 2)
	{
		if (ft_error(argv))
			return (1);
		if (stack_trick(argv, argc - 1))
			return (1);
	}
	return (0);
}
