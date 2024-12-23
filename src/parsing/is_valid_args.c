/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:09:24 by albillie          #+#    #+#             */
/*   Updated: 2024/12/23 09:39:43 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_valid_args(t_stacks *stack_a, int ac, char **av)
{
	check_chars(stack_a, ac, av);
	check_len(stack_a, ac, av);
	check_limits(stack_a, ac, av);
	check_for_doubles(stack_a);
	check_if_sorted(stack_a);
}

