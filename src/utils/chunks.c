/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 07:54:41 by albillie          #+#    #+#             */
/*   Updated: 2024/12/28 15:13:01 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunks_count(int lst_size)
{
	if (lst_size <= 200)
	{
		return (4);
	}
	else
	{
		return (8);
	}
}

void	free_chunks_list(t_chunks *chunks)
{
	if (chunks->array)
		free(chunks->array);
	free(chunks);
}
