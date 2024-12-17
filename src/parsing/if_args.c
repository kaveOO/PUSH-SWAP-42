/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:09:24 by albillie          #+#    #+#             */
/*   Updated: 2024/12/17 19:39:09 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO Check for numbers / Atol scam for long / Check doubles / Fill array

void	args_handler(int ac, char **av)
{
	fill_array(ac, av);
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
