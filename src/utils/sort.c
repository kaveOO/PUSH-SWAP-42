/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 14:23:59 by albillie          #+#    #+#             */
/*   Updated: 2025/01/02 01:04:50 by kaveo            ###   ########.fr       */
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

void	first_moves(t_stacks **sa, t_stacks **sb)
{
	ft_pb(sb, sa);
	sort_3_digits(sa);
}

void	sort_4_digits(t_stacks	**sa, t_stacks **sb, t_mimax *mimax)
{
	first_moves(sa, sb);
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

void	sort_5_digits_end(t_stacks **sa, t_stacks **sb, t_mimax *mimax)
{
	if ((*sb)->data > (*sa)->next->next->data && (*sb)->data
		< find_lower(sa, mimax))
	{
		ft_rra(sa, false);
		ft_pa(sa, sb);
		ft_ra(sa, false);
		ft_ra(sa, false);
	}
	else if ((*sb)->data < find_lower(sa, mimax) && (*sb)->data
		> (*sa)->next->next->data)
	{
		ft_rra(sa, false);
		ft_pa(sa, sb);
		ft_ra(sa, false);
		ft_ra(sa, false);
	}
	else if ((*sb)->data < find_lower(sa, mimax) && (*sb)->data
		> (*sa)->next->data)
	{
		ft_ra(sa, false);
		ft_ra(sa, false);
		ft_pa(sa, sb);
		ft_rra(sa, false);
		ft_rra(sa, false);
	}
}

void	sort_5_digits(t_stacks **sa, t_stacks **sb, t_mimax *mimax)
{
	ft_pb(sb, sa);
	sort_4_digits(sa, sb, mimax);
	if ((*sb)->data < (*sa)->data)
		ft_pa(sa, sb);
	else if ((*sb)->data > (*sa)->data && (*sb)->data < (*sa)->next->data)
	{
		ft_pa(sa, sb);
		ft_sa(*sa, false);
	}
	else if ((*sb)->data > (*sa)->next->data && (*sb)->data
		< (*sa)->next->next->data)
	{
		ft_ra(sa, false);
		ft_pa(sa, sb);
		ft_sa(*sa, false);
		ft_rra(sa, false);
	}
	else if ((*sb)->data > find_lower(sa, mimax) && (*sb)->data
		> (*sa)->next->next->data)
	{
		ft_pa(sa, sb);
		ft_ra(sa, false);
	}
	else
		sort_5_digits_end(sa, sb, mimax);
}
