/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:44:08 by albillie          #+#    #+#             */
/*   Updated: 2024/12/06 08:10:55 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	args_checker(int argc, char **argv)
{
	int	i;
	if (argc < 2)
		ft_printf("Error\n"), exit(1);
	if (argc == 2)
	{
		ft_printf("%d\n", count_args(argv[1]));
	}
	i = 1;
	if (argc > 2)
	{
		while (i < argc)
		{
			check_chars(argv[i]);
			printf("%d\n", ft_atoi(argv[i]));
			i++;
		}
	}
}

void	check_chars(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			printf("Error\n"), exit(1);
		}
		i++;
	}
}


int	count_args(char *str)
{
	int		i;
	int		args;

	i = 0;
	args = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]))
		{
			i++;
		}
		if (str[i])
		{
			args++;
		}
		while (str[i] && !ft_isspace(str[i]))
		{
			i++;
		}
	}
	return (args);
}
