/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:49:52 by silndoj           #+#    #+#             */
/*   Updated: 2024/08/04 23:19:03 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	remote_main(int argc, char **argv)
{
	char	*str;

	str = NULL;
	if (argc == 2)
	{
		if (ft_error_single(argv[1]))
			return (1);
		else
			sstack_trick(argv[1]);
	}
	else if (argc > 2)
	{
		str = args_to_single(argv);
		if (ft_error_single(str))
			return (free(str), 1);
		sstack_trick(str);
		free(str);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc == 2 && !argv[1][0])
	{
		ft_printf("Error\n");
		return (1);
	}
	else if (argc == 1)
		return (1);
	else if (argc >= 2)
		remote_main(argc, argv);
}
