/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 07:57:38 by kaveo             #+#    #+#             */
/*   Updated: 2024/12/20 15:30:37 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*stack_lst_new(int data)
{
	t_stacks	*stack;

	stack = malloc(sizeof(t_stacks));
	if (!stack)
		exit_handler(NULL, 1);
	stack->stack_a = data;
	stack->next = NULL;
	return (stack);
}

void	stack_add_back(t_stacks **list, t_stacks *data)
{
	t_stacks	*ptr;

	ptr = (*list);
	if (!ptr)
		return ;
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	ptr->next = data;
}

void	print_stack_list(t_stacks *list)
{
	while (list->next)
	{
		ft_printf("%d\n", list->stack_a);
		list = list->next;
	}
	ft_printf("%d\n", list->stack_a);
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
