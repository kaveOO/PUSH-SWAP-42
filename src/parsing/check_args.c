/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:11:24 by albillie          #+#    #+#             */
/*   Updated: 2024/12/11 00:14:41 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	args_checker(t_parsed *parsed, int argc, char **argv)
{
	int	i;

	if (argc == 0)
		exit(1);
	i = 0;
	if (argc == 2)
		check_when_string(parsed, argv[1]);
	i = 1;
	if (argc > 2)
	{
		while (i < argc)
		{
			if (!check_chars(argv[i]))
				ft_printf("Error\n"), exit(1);
			i++;
		}
	}
}