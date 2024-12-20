/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:09:24 by albillie          #+#    #+#             */
/*   Updated: 2024/12/20 08:59:31 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*args_handler(int ac, char **av)
{
	t_stacks *stacks;
	int	i;

	i = 1;
	while (i < ac)
	{
		check_chars(av[i]);
		check_limits(av[i]);
		check_len(av[i]);
		if (i == 1)
			stacks = stack_lst_new(ft_atoi(av[i]));
		else
			stack_add_back(&stacks, stack_lst_new(ft_atoi(av[i])));
		i++;
	}
	check_for_doubles(stacks);
	check_if_sorted(stacks);
	return (stacks);
}

