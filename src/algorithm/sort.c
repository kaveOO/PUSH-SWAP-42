/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:21:36 by kaveo             #+#    #+#             */
/*   Updated: 2025/01/02 00:08:47 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (get_list_size(*sb) == 1)
	{
		ft_pa(sa, sb);
		return ;
	}
	ft_pa(sa, sb);
	ft_ra(sa, false);
	mimax->down++;
}

void	push_to_a(t_stacks **sa, t_stacks **sb, t_mimax *mimax)
{
	while (*sb || mimax->down != 0)
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
		else if (get_index(sb, mimax->max) >= get_list_size(*sb) / 2)
			ft_rrb(sb, false);
		else if (get_index(sb, mimax->max) < get_list_size(*sb) / 2)
			ft_rb(sb, false);
	}
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
	else if (get_list_size(*sa) == 5)
		sort_5_digits(sa, sb, mimax);
	else if (get_list_size(*sa) > 3)
	{
		chunk_sort(sa, sb, chks);
		push_to_a(sa, sb, mimax);
	}
}
