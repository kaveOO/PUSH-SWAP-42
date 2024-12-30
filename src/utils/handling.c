/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:25:34 by albillie          #+#    #+#             */
/*   Updated: 2024/12/30 12:56:43 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_handler(t_stacks *sa, t_stacks *sb, t_chunks *chunks, int i)
{
	if (chunks)
		free_chunks_list(chunks);
	if (sa)
		free_stack_list(sa);
	if (sb)
		free_stack_list(sb);
	if (i == 1)
		write(2, "Error\n", 6);
	exit(1);
}

void	free_chunks_list(t_chunks *chunks)
{
	if (chunks->array)
		free(chunks->array);
	free(chunks);
}

void	free_stack_list(t_stacks *list)
{
	t_stacks	*temp;

	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
}
