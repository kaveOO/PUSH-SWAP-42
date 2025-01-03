/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 07:57:38 by kaveo             #+#    #+#             */
/*   Updated: 2025/01/02 00:50:35 by kaveo            ###   ########.fr       */
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

long	get_list_size(t_stacks *stack)
{
	long	i;

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

void	print_stack_list(t_stacks **list)
{
	t_stacks	*ptr;

	ptr = (*list);
	while (ptr->next)
	{
		ft_printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	ft_printf("%d\n", ptr->data);
}
