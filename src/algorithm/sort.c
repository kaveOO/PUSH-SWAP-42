/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:21:36 by kaveo             #+#    #+#             */
/*   Updated: 2024/12/29 00:34:47 by kaveo            ###   ########.fr       */
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
		chunk_sort(stack_a, stack_b, chunks);
		push_to_a(stack_a, stack_b, chunks);
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

int	find_bigger(t_stacks **stack_b, t_chunks *chunks)
{
	t_stacks	*ptr;
	int			i;

	ptr = *stack_b;
	i = 0;
	while (ptr->next)
	{
		if (ptr->data > chunks->bigger)
		{
			chunks->bigger = ptr->data;
		}
		ptr = ptr->next;
		i++;
	}
	if (!i)
		return (-1);
	return (i);
}

void	push_to_a(t_stacks **stack_a, t_stacks **stack_b, t_chunks *chunks)
{
	t_stacks	*ptr;

	ptr = *stack_b;
	while (ptr->next)
	{
		find_bigger(stack_b, chunks);
		if (ptr->data == chunks->bigger)
			ft_pa(stack_a, stack_b);
		else
		{
			// ft_printf("\n%d\n", chunks->bigger);
			// ft_printf("%d\n", find_bigger(stack_b, chunks));
			print_stack_list(*stack_b);
			ft_rrb(stack_b, false);
			print_stack_list(*stack_b);
			ft_pa(stack_a, stack_b);
			ft_printf("\n\n");
			print_stack_list(*stack_a);
		}
	}
}

void chunk_sort(t_stacks **sa, t_stacks **sb, t_chunks *chunks)
{
	while (*sa)
	{
		int count = get_element_pos(chunks, (*sa)->data);
		if (count == 1)
		{
			ft_pb(sb, sa);
		}
		else if (count == -1)
		{
			ft_pb(sb, sa);
			ft_rb(sb, false);
		}
		else
		{
			ft_ra(sa, false);
		}
		update_chunks_pos(chunks, sa);
	}
}

bool elements_in_chunks(t_chunks *chunks, t_stacks **stack_a)
{
	int i = 0;
	int j;
	t_stacks	*ptr = (*stack_a);
	if (!ptr)
		return NULL;
	while (i < chunks->size && ptr->next)
	{
		j = chunks->start;
		while (j <= chunks->end)
		{
			if (ptr->data == chunks->array[j])
				return (true);
			j++;
		}
		ptr = ptr->next;
		i++;
	}
	return (false);
}
void update_chunks_pos(t_chunks *chunks, t_stacks **stack_a)
{
	if (!elements_in_chunks(chunks, stack_a))
	{
		if (chunks->start - chunks->offset < 0)
			chunks->start -= chunks->start;
		else
			chunks->start -= chunks->offset;
		if (chunks->end + chunks->offset > chunks->size)
			chunks->end = chunks->size - 1;
		else
			chunks->end += chunks->offset;
	}
}
