/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:09:24 by albillie          #+#    #+#             */
/*   Updated: 2024/12/18 06:50:01 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO Check for numbers / Atol scam for long / Check doubles / Fill array

void	args_handler(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		check_chars(av[i]);
		check_limits(av[i]);
		check_len(av[i]);
		i++;
	}


	// fill_array(ac, av);
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


int	args_counter(int ac)
{
	int	i;

	i = 0;
	while (i < ac)
		i++;
	return(i - 1);
}

int	*fill_array(int ac, char **av)
{
	int	i;
	int args;
	int	*array;

	i = 0;
	args = args_counter(ac);
	array = malloc(sizeof(int *) * (args + 1));
	if (!array)
		return (NULL);
	while (args >= 0)
	{
		array[i] = ft_atoi(av[i]);
		ft_printf("%d\n", array[i]);
		args--;
		i++;
	}
	return (array);
}
