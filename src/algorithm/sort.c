/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:21:36 by kaveo             #+#    #+#             */
/*   Updated: 2024/12/29 22:28:03 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_list(t_stacks **sa, t_stacks **sb, t_chunks *chks, t_mimax *mimax)
{
	(void)sb;
	if (get_list_size(*sa) == 2)
		ft_sa(*sa, false);
	else if (get_list_size(*sa) == 3)
		sort_3_digits(sa);
	else if (get_list_size(*sa) > 3)
	{
		chunk_sort(sa, sb, chks);
		// ft_printf("\nlist size %d\n", get_list_size(*sb) / 2);
		// ft_printf("bigger index %d\n", find_bigger(sb, mimax));
		push_to_a(sa, sb, chks, mimax);
		// (void) mimax;
		// find_bigger(sb, &mimax);
		// while ((*sb)->data != mimax->max)
		// {
		// 	ft_rb(sb, false);
		// }
		// ft_pa(sa, sb);
		// print_stack_list(*sb);
		// ft_pa(sa,sb);
		// print_stack_list(*sb);
		// ft_rb(sb, false);
		// ft_pa(sa, sb);
		// ft_printf("\n");
		// print_stack_list(*sb);
		// find_bigger(sb, &mimax);
		// ft_printf("\n%d\n", mimax->max);
		// while ((*sb)->data != mimax->max)
		// {
		// 	ft_rb(sb, false);
		// }
		// print_stack_list(*sb);
		// ft_pa(sa, sb);
		// ft_ra(sa, false);
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

int	find_bigger(t_stacks **stack_b, t_mimax **mimax)
{
	t_stacks *ptr;
	int i;

	ptr = (*stack_b);
	if (!ptr)
		return (0);
	i = 0;
	if (!ptr->next)
		return (1);
	(*mimax)->max = 0;
	while (ptr->next)
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

void push_to_a(t_stacks **sa, t_stacks **sb, t_chunks *chks, t_mimax *mimax)
{

	(void)sa;
	(void)chks;
	int down = 0;
	while (*sb)
	{
		find_bigger(sb, &mimax);
		if (get_list_size(*sb) == 1)
		{
			ft_pa(sa, sb);
		}
		else if (mimax->max == (*sb)->data)
		{
			ft_pa(sa, sb);
		}
		else if (down == 0 || (*sb)->data > mimax->min)
		{
			ft_pa(sa, sb);
			down++;
		}
		else if (find_bigger(sb, &mimax) >= get_list_size(*sb) / 2)
		{
			while ((*sb)->data != mimax->max)
			{
				ft_rb(sb, false);
			}
			ft_pa(sa, sb);
		}
		else if (find_bigger(sb, &mimax) < get_list_size(*sb) / 2)
		{
			while ((*sb)->data != mimax->max)
			{
				ft_rrb(sb, false);
			}
			ft_pa(sa, sb);
		}
	}
	print_stack_list(*sa);
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
	t_stacks *ptr = (*stack_a);
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
