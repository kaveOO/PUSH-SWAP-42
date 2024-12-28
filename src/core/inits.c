/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:39:47 by kaveo             #+#    #+#             */
/*   Updated: 2024/12/28 23:48:05 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*init_stack_a(int ac, char **av)
{
	t_stacks	*stack_a;
	int	i;

	i = 1;
	while (i < ac)
	{
		if (i == 1)
		{
			stack_a = stack_lst_new(ft_atoi(av[i]));
		}
		else
			stack_add_back(&stack_a, stack_lst_new(ft_atoi(av[i])));
		i++;
	}
	return (stack_a);
}

t_chunks	*init_chunks_stack(t_stacks **stack_a)
{
	t_chunks	*chunks;

	chunks = malloc(sizeof(t_chunks));
	if (!chunks)
		return NULL;
	chunks->size = get_list_size(*stack_a);
	chunks->array = fill_sort_array(stack_a);
	chunks->chunks_count = get_chunks_count(get_list_size(*stack_a));
	chunks->middle = chunks->size / 2;
	chunks->offset = chunks->size / chunks->chunks_count;
	chunks->start = chunks->middle - chunks->offset;
	chunks->end = chunks->middle + chunks->offset;
	chunks->bigger = 0;
	return (chunks);
}
