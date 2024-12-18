/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:16:12 by kaveo             #+#    #+#             */
/*   Updated: 2024/12/18 21:29:43 by kaveo            ###   ########.fr       */
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
void	stack_add_back(t_parsing **list, int data)
{
	t_parsing	*ptr;

	ptr = (*list);
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	ptr->data = data;
}
