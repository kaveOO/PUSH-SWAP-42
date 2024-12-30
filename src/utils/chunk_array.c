/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 03:32:27 by albillie          #+#    #+#             */
/*   Updated: 2024/12/30 12:51:48 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*fill_sort_array(t_stacks **stack_a)
{
	t_stacks	*ptr;
	int			*array;
	int			i;

	array = malloc(sizeof(int *) * (get_list_size(*stack_a) + 1));
	if (!array)
		return (NULL);
	ptr = (*stack_a);
	i = 0;
	while (ptr)
	{
		array[i] = ptr->data;
		ptr = ptr->next;
		i++;
	}
	array[i] = '\0';
	return (bubble_sort_array(array));
}

void	print_array(int *array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_printf("%d ", array[i]);
		i++;
	}
	ft_printf("\n");
	ft_printf("\n");
}

int	get_array_size(int *array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		i++;
	}
	return (i);
}

int	*bubble_sort_array(int *array)
{
	int	i;
	int	j;

	i = 0;
	while (i < get_array_size(array))
	{
		j = 0;
		while (j < get_array_size(array) - 1)
		{
			if (array[j] > array[j + 1])
			{
				ft_swap(&array[j], &array[j + 1]);
			}
			j++;
		}
		i++;
	}
	return (array);
}
