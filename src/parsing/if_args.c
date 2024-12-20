/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:09:24 by albillie          #+#    #+#             */
/*   Updated: 2024/12/20 07:40:04 by kaveo            ###   ########.fr       */
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
void	check_len(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == '+' || str[i] == '-' || str[i] == '0')
		str++;
	while (ft_isdigit(str[i]))
		i++;
	if (i > ft_strlen("9223372036854775807"))
		exit_handler(NULL, 1);
}

void	check_limits(char *str)
{
	if (ft_atol(str) > INT_MAX || ft_atol(str) < INT_MIN)
		exit_handler(NULL, 1);
}

