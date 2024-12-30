/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:54:47 by albillie          #+#    #+#             */
/*   Updated: 2024/12/30 13:08:34 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort(t_stacks **sa, t_stacks **sb, t_chunks *chunks)
{
	int	count;
	
	while (*sa)
	{

		count = get_element_pos(chunks, (*sa)->data);
		if (count == 1)
		{
			ft_pb(sb, sa);
		}
		else if (count == -1)
		{
			ft_pb(sb, sa);
			ft_rb(sb, false);
		}
		else
		{
			ft_ra(sa, false);
		}
		update_chunks_pos(chunks, sa);
	}
}
