/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:21:36 by kaveo             #+#    #+#             */
/*   Updated: 2024/12/30 13:07:28 by albillie         ###   ########.fr       */
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

void	push_to_a(t_stacks **sa, t_stacks **sb, t_mimax *mimax)
{
	int	down;

	down = 0;
	while (*sb)
	{
		find_bigger(sb, &mimax);
		find_lower(sa, mimax);
		if (mimax->max == (*sb)->data)
		{
			if (mimax->min > mimax->max)
			{
				ft_rra(sa, false);
				down--;
			}
			else
				ft_pa(sa, sb);
		}
		else if (down == 0 || (*sb)->data > mimax->min)
		{
			ft_pa(sa, sb);
			ft_ra(sa, false);
			down++;
		}
		if (get_list_size(*sb) == 1)
		{
			while (down != 0)
			{
				if ((find_bigger(sb, &mimax)) > find_lower(sa, mimax))
				{
					ft_pa(sa, sb);
					ft_rra(sa, false);
					down--;
				}
				else if ((find_bigger(sb, &mimax)) < find_lower(sa, mimax))
				{
					ft_rra(sa, false);
					down--;
				}
			}
		}
		else if (get_index(sb, mimax) >= get_list_size(*sb) / 2)
			ft_rrb(sb, false);
		else if (get_index(sb, mimax) < get_list_size(*sb) / 2)
			ft_rb(sb, false);
	}
}

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
		push_to_a(sa, sb, mimax);
	}
}


