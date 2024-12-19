/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:12:44 by albillie          #+#    #+#             */
/*   Updated: 2024/12/19 20:06:47 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_chars(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (!ft_isdigit(str[i]))
			exit_error(NULL);
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			exit_error(NULL);
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
