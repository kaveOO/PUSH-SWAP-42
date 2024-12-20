/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:11:24 by albillie          #+#    #+#             */
/*   Updated: 2024/12/20 08:59:02 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*args_checker(int argc, char **argv)
{
	if (argc <= 2)
		exit(1);
	if (argc > 2)
	{
		return (args_handler(argc, argv));
	}
	return (NULL);
}
