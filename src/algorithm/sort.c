/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:21:36 by kaveo             #+#    #+#             */
/*   Updated: 2024/12/31 12:51:20 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_digits(t_stacks **stack_a)
{
	if (((*stack_a)->data > (*stack_a)->next->data)
		&& ((*stack_a)->data > (*stack_a)->next->next->data))
	{
		ft_ra(stack_a, false);
	}
	else if ((*stack_a)->next->data > (*stack_a)->data && (*stack_a)->next->data
		> (*stack_a)->next->next->data)
	{
		ft_rra(stack_a, false);
	}
	if ((*stack_a)->data > (*stack_a)->next->data)
	{
		ft_sa(*stack_a, false);
	}
}
void	sort_4_digits(t_stacks	**sa, t_stacks **sb, t_mimax *mimax)
{
	ft_pb(sb, sa);
	sort_3_digits(sa);
	print
}

void	handle_the_end(t_stacks **sb, t_stacks **sa, t_mimax *mimax)
{
	while (mimax->down != 0)
	{
		if ((find_bigger(sb, &mimax)) > find_lower(sa, mimax))
		{
			ft_pa(sa, sb);
			ft_rra(sa, false);
			mimax->down--;
		}
		else if ((find_bigger(sb, &mimax)) < find_lower(sa, mimax))
		{
			ft_rra(sa, false);
			mimax->down--;
		}
	}
}
void	handle_the_bottom(t_stacks **sa, t_stacks **sb, t_mimax *mimax)
{
	ft_pa(sa, sb);
	ft_ra(sa, false);
	mimax->down++;
}

void	push_to_a(t_stacks **sa, t_stacks **sb, t_mimax *mimax)
{
	while (*sb)
	{
		find_bigger(sb, &mimax);
		find_lower(sa, mimax);
		if (mimax->max == (*sb)->data)
		{
			if (mimax->min > mimax->max)
			{
				ft_rra(sa, false);
				mimax->down--;
			}
			else
				ft_pa(sa, sb);
		}
		else if (mimax->down == 0 || (*sb)->data > mimax->min)
			handle_the_bottom(sa, sb, mimax);
		if (get_list_size(*sb) == 1)
			handle_the_end(sb, sa, mimax);
		else if (get_index(sb, mimax) >= get_list_size(*sb) / 2)
			ft_rrb(sb, false);
		else if (get_index(sb, mimax) < get_list_size(*sb) / 2)
			ft_rb(sb, false);
	}
	ft_rrb(sa, sb);
}

void	sort_list(t_stacks **sa, t_stacks **sb, t_chunks *chks, t_mimax *mimax)
{
	(void)sb;
	if (get_list_size(*sa) == 2)
		ft_sa(*sa, false);
	else if (get_list_size(*sa) == 3)
		sort_3_digits(sa);
	else if (get_list_size(*sa) == 4)
		sort_4_digits(sa, sb, mimax);
	else if (get_list_size(*sa) > 3)
	{
		chunk_sort(sa, sb, chks);
		push_to_a(sa, sb, mimax);
	}
}
