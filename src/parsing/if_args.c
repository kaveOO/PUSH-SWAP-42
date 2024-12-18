/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:09:24 by albillie          #+#    #+#             */
/*   Updated: 2024/12/18 20:15:01 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO Check for numbers / Atol scam for long / Check doubles / Fill array
// TODO If i == 1,  make lst new, else just make lst add back with numbers to fill the array

void	args_handler(int ac, char **av)
{
	t_parsing *parsing;

	parsing = malloc(sizeof(t_parsing));
	int	i;

	i = 1;
	while (i < ac)
	{
		check_chars(av[i]);
		check_limits(av[i]);
		check_len(av[i]);
		i++;
	}
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

