/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:11:24 by albillie          #+#    #+#             */
/*   Updated: 2024/12/16 15:11:37 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	args_checker(t_stacks *stack, int argc, char **argv)
{
	int	i;

	if (argc == 0)
		exit(1);
	i = 1;
	if (argc > 2)
	{
		while (i < argc)
		{
			check_when_args(stack, argv[i]);
			i++;
		}
	}
}
