/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:11:24 by albillie          #+#    #+#             */
/*   Updated: 2024/12/17 19:14:03 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	args_checker(int argc, char **argv)
{
	if (argc == 0)
		exit(1);
	if (argc > 2)
	{
		args_handler(argc, argv);
	}
}
