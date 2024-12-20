/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:16:12 by kaveo             #+#    #+#             */
/*   Updated: 2024/12/20 07:39:10 by kaveo            ###   ########.fr       */
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
		return;
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
	t_stacks *temp;

	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
}

void	check_for_doubles(t_stacks *list)
{
	t_stacks *current;
	t_stacks *temp;

	current = list;
	while (current)
	{
		temp = current;
		while (temp->next)
		{
			if (temp->next->stack_a == current->stack_a)
				exit_handler(list, 1);
			temp = temp->next;
		}
		current = current->next;
	}
}

void	check_if_sorted(t_stacks *stack_a)
{
	t_stacks	*ptr;

	ptr = stack_a;
	while (ptr->next != NULL)
	{
		if (ptr->stack_a > ptr->next->stack_a)
			return;
		ptr = ptr->next;
	}
	exit_handler(stack_a, 0);
}
