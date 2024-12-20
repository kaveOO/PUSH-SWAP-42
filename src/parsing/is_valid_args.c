/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:09:24 by albillie          #+#    #+#             */
/*   Updated: 2024/12/20 16:29:32 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*init_a_stack(int ac, char **av)
{
	t_stacks	*stack_a;
	int	i;

	i = 1;
	while (i < ac)
	{
		if (i == 1)
			stack_a = stack_lst_new(ft_atoi(av[i]));
		else
			stack_add_back(&stack_a, stack_lst_new(ft_atoi(av[i])));
		i++;
	}
	return (stack_a);
}

void	is_valid_args(t_stacks *stack_a, int ac, char **av)
{
	check_chars(stack_a, ac, av);
	check_len(stack_a, ac, av);
	check_limits(stack_a, ac, av);
	check_for_doubles(stack_a);
	check_if_sorted(stack_a);
}

