/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:09:24 by albillie          #+#    #+#             */
/*   Updated: 2025/01/02 00:50:17 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_valid_args(int ac, char **av)
{
	if (!check_chars(ac, av))
		return (false);
	else if (!check_limits(ac, av))
		return (false);
	else if (!check_len(ac, av))
		return (false);
	else
		return (true);
}

void	check_doubles_and_sorted(t_stacks *stack_a)
{
	if (!check_for_doubles(stack_a))
		exit_handler(stack_a, NULL, NULL, 1);
	if (check_if_sorted(stack_a))
		exit_handler(stack_a, NULL, NULL, 0);
}
