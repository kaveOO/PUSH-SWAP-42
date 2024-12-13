/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:16:12 by kaveo             #+#    #+#             */
/*   Updated: 2024/12/19 15:06:07 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_parsing	*stack_lst_new(int data)
{
	t_parsing	*parsing;

	parsing = malloc(sizeof(t_parsing));
	if (!parsing)
		exit_parsing();
	parsing->data = data;
	parsing->next = NULL;
	return (parsing);
}
void	stack_add_back(t_parsing **list, t_parsing *data)
{
	t_parsing	*ptr;

	ptr = (*list);
	if (!ptr)
		return;
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	ptr->next = data;
}
void	print_stack_list(t_parsing *list)
{
	while (list->next)
	{
		ft_printf("%d\n", list->data);
		list = list->next;
	}
	ft_printf("%d\n", list->data);
}

