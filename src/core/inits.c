/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:39:47 by kaveo             #+#    #+#             */
/*   Updated: 2024/12/25 01:05:03 by kaveo            ###   ########.fr       */
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
			stack_a = stack_lst_new(ft_atoi(av[i]));
		else
			stack_add_back(&stack_a, stack_lst_new(ft_atoi(av[i])));
		i++;
	}
	return (stack_a);
}

t_stacks	*init_b_stack(t_stacks *stack_a)
{
	t_stacks	*stack_b;

	stack_b = malloc(sizeof(t_stacks));
	stack_b->data = stack_a->data;
	stack_b->next = malloc(sizeof(t_stacks));
	stack_b->next->data = stack_a->next->data;
	stack_b->next->next = NULL;
	return (stack_b);
}
