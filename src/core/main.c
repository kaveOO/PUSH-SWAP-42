/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:06:19 by albillie          #+#    #+#             */
/*   Updated: 2025/01/02 00:49:55 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	*stack_a;
	t_stacks	*stack_b;
	t_chunks	*chunks;
	t_mimax		*mimax;

	if (ac <= 2)
		exit(1);
	if (!is_valid_args(ac, av))
		exit_handler(NULL, NULL, NULL, 1);
	stack_a = init_stack_a(ac, av);
	check_doubles_and_sorted(stack_a);
	chunks = init_chunks_stack(&stack_a);
	stack_b = NULL;
	mimax = init_mimax();
	sort_list(&stack_a, &stack_b, chunks, mimax);
	free(mimax);
	exit_handler(stack_a, stack_b, chunks, 0);
}
