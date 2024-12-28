/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:39:47 by kaveo             #+#    #+#             */
/*   Updated: 2024/12/28 06:03:59 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*init_a_stack(int ac, char **av)
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

// t_chunks	*init_chunks_stack(t_stacks **stack_a)
// {
// 	t_chunks	*chunks;

// 	chunks = malloc(sizeof(t_chunks));
// 	if (!chunks)
// 		return NULL;
// 	chunks->array =



// }
