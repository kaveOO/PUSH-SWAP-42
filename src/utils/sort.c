/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 14:23:59 by albillie          #+#    #+#             */
/*   Updated: 2025/01/01 17:56:48 by albillie         ###   ########.fr       */
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
	(void) mimax;
	ft_pb(sb, sa);
	sort_3_digits(sa);
	if ((*sb)->data < (*sa)->data)
		ft_pa(sa, sb);
	else if ((*sb)->data < (*sa)->next->data)
	{
		ft_pa(sa, sb);
		ft_sa(*sa, false);
	}
	else if ((*sb)->data > find_lower(sa, mimax))
	{
		ft_pa(sa, sb);
		ft_ra(sa, false);
	}
	else if ((*sb)->data < (*sa)->next->data)
	{
		ft_ra(sa, false);
		ft_pa(sa, sb);
	}
	else if ((*sb)->data > (*sa)->next->data)
	{
		ft_rra(sa, false);
		ft_pa(sa, sb);
		ft_ra(sa, false);
		ft_ra(sa, false);
	}
}

void	sort_5_digits(t_stacks **sa, t_stacks **sb, t_mimax *mimax, t_chunks *cks)
{
	(void) cks;
	ft_pb(sb, sa);
	sort_4_digits(sa, sb, mimax);
	if ((*sb)->data < (*sa)->data)
		ft_pa(sa, sb);
	else if ((*sb)->data < (*sa)->next->data)
	{
		ft_pa(sa, sb);
		ft_sa(*sa, false);
	}
	else if ((*sb)->data > find_lower(sa, mimax))
	{
		ft_pa(sa, sb);
		ft_ra(sa, false);
	}
	else if ((*sb)->data < (*sa)->next->next->data)
	{
		ft_rra(sa, false);
		ft_rra(sa, false);
		ft_pa(sa, sb);
		ft_ra(sa, false);
		ft_ra(sa, false);
		ft_ra(sa, false);
	}
	else if ((*sb)->data < find_lower(sa, mimax))
	{
		ft_rra(sa, false);
		ft_pa(sa, sb);
		ft_ra(sa, false);
		ft_ra(sa, false);
	}
}
