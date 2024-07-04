/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_specific.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:22:45 by silndoj           #+#    #+#             */
/*   Updated: 2024/07/04 17:15:19 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap_specific(int *sstack, int pos_1,int s_replace, int len)
{
	int	i;
	int	flag;
	int	pos_2;

	i = 0;
	flag = 1;
	while (flag == 1)
	{
		while (i <= len)
		{
			if (sstack[i] == s_replace)
				pos_2 = i;
			i++;
		}
		if ((pos_2 < pos_1) && sstack[pos_1] != s_replace)
			if (pos_2 < len / 2)
				trick_ra(sstack, len);
		if ((pos_2 > pos_1) && sstack[pos_1] != s_replace)
			trick_rra(sstack, len);
		if (sstack[pos_1] == s_replace)
			flag = 0;
	}
}
