/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:06:19 by albillie          #+#    #+#             */
/*   Updated: 2024/12/28 11:02:29 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stack_a;
	t_stacks	*stack_b;
	t_chunks	*chunks;

	if (argc <= 2)
		exit(1);
	stack_b = NULL;
	stack_a = init_stack_a(argc, argv);
	chunks = init_chunks_stack(&stack_a);
	if (!is_valid_args(stack_a, argc, argv))
		exit_handler(stack_a, stack_b, chunks, 1);
	if (!check_for_doubles(stack_a))
		exit_handler(stack_a, stack_b, chunks, 0);
	sort_list(&stack_a, &stack_b);
	// {
	// 	if ((stack_a->data > stack_a->next->data) &&
	// 	(stack_a->data > stack_a->next->next->data))
	// 	{
	// 		ft_ra(&stack_a, false);
	// 	}
	// 	else if (stack_a->next->data > stack_a->data
	// 		&& stack_a->next->data > stack_a->next->next->data)
	// 	{
	// 		ft_rra(&stack_a, false);
	// 	}
	// 	if (stack_a->data > stack_a->next->data)
	// 	{
	// 		ft_sa(stack_a, false);
	// 	}
	// }
	print_stack_list(stack_a);


	exit_handler(stack_a, stack_b, chunks, 0);
}
