/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 07:54:41 by albillie          #+#    #+#             */
/*   Updated: 2024/12/30 13:03:37 by albillie         ###   ########.fr       */
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

void	update_chunks_pos(t_chunks *chunks, t_stacks **stack_a)
{
	if (!elements_in_chunks(chunks, stack_a))
	{
		if (chunks->start - chunks->offset < 0)
		{
			chunks->start -= chunks->start;
		}
		else
		{
			chunks->start -= chunks->offset;
		}
		if (chunks->end + chunks->offset > chunks->size)
		{
			chunks->end = chunks->size - 1;
		}
		else
		{
			chunks->end += chunks->offset;
		}
	}
}

int	get_element_pos(t_chunks *chunks, int data)
{
	int	i;

	i = chunks->start;
	while (i <= chunks->end)
	{
		if (chunks->array[i] == data)
		{
			if (i < chunks->middle)
			{
				return (-1);
			}
			else if (i >= chunks->middle)
			{
				return (1);
			}
		}
		i++;
	}
	return (0);
}

bool	elements_in_chunks(t_chunks *chunks, t_stacks **stack_a)
{
	t_stacks	*ptr;
	int			i;
	int			j;

	i = 0;
	ptr = (*stack_a);
	if (!ptr)
		return (NULL);
	while (i < chunks->size && ptr->next)
	{
		j = chunks->start;
		while (j <= chunks->end)
		{
			if (ptr->data == chunks->array[j])
			{
				return (true);
			}
			j++;
		}
		ptr = ptr->next;
		i++;
	}
	return (false);
}
