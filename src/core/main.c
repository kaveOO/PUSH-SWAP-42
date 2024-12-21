/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:06:19 by albillie          #+#    #+#             */
/*   Updated: 2024/12/21 09:59:31 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stack_a;
	t_stacks	*stack_b;

	if (argc <= 2)
		exit(1);
	stack_a = init_a_stack(argc, argv);
	is_valid_args(stack_a, argc, argv);
	stack_b = malloc(sizeof(stack_b));
	sort_list(argc, stack_a, stack_b);
	exit_handler(stack_a, 0);
}