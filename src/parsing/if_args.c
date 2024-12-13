/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:09:24 by albillie          #+#    #+#             */
/*   Updated: 2024/12/19 15:09:28 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO Check for numbers / Atol scam for long / Check doubles / Fill array

void print_list(t_parsing *list)
{
	t_parsing *ptr;

	ptr = list;
	while (ptr->next)
	{
		ft_printf("%d\n", list->data);
		ptr = ptr->next;
	}
}
void	args_handler(int ac, char **av)
{
	t_parsing *parsing;
	int	i;

	i = 1;
	while (i < ac)
	{
		check_chars(av[i]);
		check_limits(av[i]);
		check_len(av[i]);
		if (i == 1)
			parsing = stack_lst_new(ft_atoi(av[i]));
		else
			stack_add_back(&parsing, stack_lst_new(ft_atoi(av[i])));
		i++;
	}
	print_stack_list(parsing);
	ft_printf("\n");
	print_stack_list(parsing);
}
void	check_len(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == '+' || str[i] == '-' || str[i] == '0')
		str++;
	while (ft_isdigit(str[i]))
	{
		i++;
	}
	if (i > ft_strlen("9223372036854775807"))
	{
		exit_parsing();
	}
}

void	check_limits(char *str)
{
	if (ft_atol(str) > INT_MAX || ft_atol(str) < INT_MIN)
	{
		exit_parsing();
	}
}

