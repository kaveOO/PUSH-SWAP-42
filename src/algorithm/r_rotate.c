/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 22:57:06 by kaveo             #+#    #+#             */
/*   Updated: 2024/12/23 23:40:50 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO Have to find a way to delete the last node of linked list with no leaks and finish instructions

void	ft_rra(t_stacks **stack_a)
{
	t_stacks	*ptr;

	ptr = (*stack_a);
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->temp = ptr->data;
	stack_add_front(stack_a, stack_lst_new(ptr->data));
	// free(ptr);
	ptr = NULL;
	// ft_printf("%d\n", ptr->temp);
}

/* void	ft_rrb(t_stacks *stack_b)
{




} */
