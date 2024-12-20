/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:12:44 by albillie          #+#    #+#             */
/*   Updated: 2024/12/20 07:30:04 by kaveo            ###   ########.fr       */
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
			exit_handler(NULL, 1);
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			exit_handler(NULL, 1);
		i++;
	}
}
