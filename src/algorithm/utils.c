/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 03:32:27 by albillie          #+#    #+#             */
/*   Updated: 2024/12/28 06:41:27 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_sort_array(t_stacks **stack_a)
{
	t_stacks	*ptr;
	int			*array;
	int			i;

	array = malloc(sizeof(int *) * (get_list_size(*stack_a)));
	if (!array)
		return ;
	ptr = (*stack_a);
	i = 0;
	while (ptr)
	{
		array[i] = ptr->data;
		i++;
		ptr = ptr->next;
	}
	array[i] = '\0';
	print_array(array);
}

void	print_array(int *array)
{
	int i = 0;
	while (array[i])
	{
		ft_printf("%d\n", array[i]);
		i++;
	}
	free(array);
}


void	pre_sort_stack(t_stacks **stack_a)
{
	t_stacks	*ptr;
	t_stacks	*temp;
	int			i;

	temp = malloc(sizeof(t_stacks));
	i = 0;
	while (i < get_list_size(*stack_a))
	{
		ptr = (*stack_a);
		while (ptr->next)
		{
			if (ptr->data > ptr->next->data)
			{
				temp->data = ptr->data;
				ptr->data = ptr->next->data;
				ptr->next->data = temp->data;
			}
			ptr = ptr->next;
		}
		i++;
	}
	free(temp);
}
