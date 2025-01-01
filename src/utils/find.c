/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:57:37 by albillie          #+#    #+#             */
/*   Updated: 2025/01/01 16:35:09 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_bigger(t_stacks **stack_b, t_mimax **mimax)
{
	t_stacks	*ptr;
	int			i;

	ptr = (*stack_b);
	if (!ptr)
		return (0);
	i = 0;
	if (!ptr->next)
		return (ptr->data);
	(*mimax)->max = -2147483648;
	while (ptr)
	{
		if (ptr->data > (*mimax)->max)
		{
			(*mimax)->max = ptr->data;
		}
		ptr = ptr->next;
		i++;
	}
	if (!i)
		return (-1);
	return (i);
}

int	find_lower(t_stacks **stack_a, t_mimax *mimax)
{
	t_stacks	*ptr;

	ptr = (*stack_a);
	mimax->min = 0;
	if (!ptr)
		return (0);
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	mimax->min = ptr->data;
	return (ptr->data);
}

int	get_index(t_stacks **stack_b, int nb)
{
	int			i;
	t_stacks	*ptr;

	ptr = (*stack_b);
	i = 1;
	while (i < get_list_size(*stack_b))
	{
		if (ptr->data == nb)
			return (i);
		ptr = ptr->next;
		i++;
	}
	return (i);
}
