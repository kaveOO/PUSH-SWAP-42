/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:09:24 by albillie          #+#    #+#             */
/*   Updated: 2024/12/31 12:38:16 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_valid_args(t_stacks *stack_a, int ac, char **av)
{
	if (!check_chars(ac, av))
		return (false);
	else if (!check_limits(ac, av))
		return (false);
	else if (!check_len(ac, av))
		return (false);
	else if (!check_for_doubles(stack_a))
		return (false);
	else
		return (true);
}
