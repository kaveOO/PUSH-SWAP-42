/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 07:57:38 by kaveo             #+#    #+#             */
/*   Updated: 2024/12/30 12:56:35 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*stack_lst_new(int data)
{
	t_stacks	*stack;

	stack = malloc(sizeof(t_stacks));
	if (!stack)
		exit_handler(NULL, NULL, NULL, 1);
	stack->data = data;
	stack->next = NULL;
	return (stack);
}

void	stack_add_front(t_stacks **stack, t_stacks *data)
{
	data->next = (*stack);
	(*stack) = data;
}

void	stack_add_back(t_stacks **list, t_stacks *data)
{
	t_stacks	*ptr;

	if (!list)
		return ;
	ptr = (*list);
	if (!ptr)
		(*list) = data;
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	ptr->next = data;
}

int	get_list_size(t_stacks *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (-1);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
