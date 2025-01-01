/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 03:32:27 by albillie          #+#    #+#             */
/*   Updated: 2025/01/01 16:01:41 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*fill_sort_array(t_stacks **stack_a, int size)
{
	t_stacks	*ptr;
	int			*array;
	int			i;

	array = malloc(sizeof(int *) * (size + 1));
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
	return (bubble_sort_array(array, size));
}

void	print_array(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d ", array[i]);
		i++;
	}
}

int	*bubble_sort_array(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
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
