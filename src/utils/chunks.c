/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 07:54:41 by albillie          #+#    #+#             */
/*   Updated: 2024/12/28 08:46:42 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunks_count(int lst_size)
{
	int	chunks_count;

	chunks_count = 0;
	if (lst_size <= 10)
	{
		chunks_count = 5;
	}
	else if (lst_size <= 150)
	{
		chunks_count = 8;
	}
	else if (lst_size > 150)
	{
		chunks_count = 18;
	}
	return (chunks_count);
}

void	free_chunks_list(t_chunks *chunks)
{
	// if (chunks->array)
	// 	free_chunks_array(chunks->array);
	free(chunks->array);
	free(chunks);
	chunks = NULL;
}
