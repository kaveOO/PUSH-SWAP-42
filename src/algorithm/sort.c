/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:21:36 by kaveo             #+#    #+#             */
/*   Updated: 2024/12/28 20:29:13 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_list(t_stacks **stack_a, t_stacks **stack_b, t_chunks *chunks)
{
	(void)stack_b;
	if (get_list_size(*stack_a) == 2)
		ft_sa(*stack_a, false);
	else if (get_list_size(*stack_a) == 3)
		sort_3_digits(stack_a);
	else if (get_list_size(*stack_a) > 3)
	{
		*stack_b = stack_lst_new(452);
		// print_stack_list(*stack_b);
		// ft_pa(stack_a, stack_b);
		// ft_printf("\n");
		print_array(chunks->array);
		chunk_sort(stack_a, stack_b, chunks);
		// ft_printf("%d\n", chunks->size);
		// int i = 0;
		// while (i < chunks->size)
		// {
		// 	ft_printf("%d\n", chunks->array[i]);
		// 	i++;
		// }
		//ft_pa(stack_a, stack_b);

		//print_stack_list(*stack_a);
		//ft_printf("\n");
		//print_stack_list(*stack_b);
	}	
}

void sort_3_digits(t_stacks **stack_a)
{
	if (((*stack_a)->data > (*stack_a)->next->data) &&
		((*stack_a)->data > (*stack_a)->next->next->data))
	{
		ft_ra(stack_a, false);
	}
	else if ((*stack_a)->next->data > (*stack_a)->data && (*stack_a)->next->data > (*stack_a)->next->next->data)
	{
		ft_rra(stack_a, false);
	}
	if ((*stack_a)->data > (*stack_a)->next->data)
	{
		ft_sa(*stack_a, false);
	}
}
int get_element_pos(t_chunks *chunks, int data)
{
	int i;

	i = chunks->start;
	while (i <= chunks->end)
	{
		if (chunks->array[i] == data)
		{
			if (i < chunks->middle)
				return -1;
			else if (i >= chunks->middle)
				return 1;
		}
		i++;
	}
	return 0;
}

void chunk_sort(t_stacks **sa, t_stacks **sb, t_chunks *chunks)
{
	// t_stacks *ptr;
	(void)sb;
	(void)chunks;
	(void) sa;
	int i = 0;

	t_stacks	*ptr;
	ptr = (*sa);
	while (i < get_list_size(*sa))
	{
		ptr = (*sa);
		if (get_element_pos(chunks, ptr->data) == -1)
		{
			ft_pb(sb, sa);
			ft_rb(sb, true);
			//printf("test -1\n");
		}
		else if (get_element_pos(chunks, ptr->data) == 1)
		{
			ft_pb(sb, sa);
		}
		else
		{
			ft_ra(sa, true);
		}
		update_chunks_pos(chunks, sa);
	}
}

bool elements_in_chunks(t_chunks *chunks, t_stacks **stack_a)
{
	(void) stack_a;

	int i = 1;
	int j;
	t_stacks	*ptr = (*stack_a);
	if (!ptr)
		return NULL;
	while (i < chunks->size && i < get_list_size(*stack_a))
	{
		j = chunks->start;
		while (j <= chunks->end)
		{
			if (ptr->data == chunks->array[j])
			{
				//ft_printf("\n%d\n", chunks->array[j]);
				//ft_printf("\n%d\n", ptr->data);
				return (true);
			}
			j++;
		}
		ptr = ptr->next;
		i++;
	}
	return (false);
}
void update_chunks_pos(t_chunks *chunks, t_stacks **stack_a)
{
	if (elements_in_chunks(chunks, stack_a))
	{
		if (chunks->start - chunks->offset < 0)
			chunks->start -= chunks->start;
		else
			chunks->start -= chunks->offset;
		if (chunks->end + chunks->offset > chunks->size)
			chunks->end = chunks->offset - 1;
		else
			chunks->end += chunks->offset;
	}
}
