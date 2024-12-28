/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:06:19 by albillie          #+#    #+#             */
/*   Updated: 2024/12/28 02:26:17 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO Have to fix ft_ra && ft_rb, theses functions are leaking because of lstnew !

int	main(int argc, char **argv)
{
	t_stacks	*stack_a;
	t_stacks	*stack_b;

	if (argc <= 2)
		exit(1);
	stack_a = init_a_stack(argc, argv);
	stack_b = stack_lst_new(42);
	stack_add_back(&stack_b, stack_lst_new(35));
	// stack_b = stack_lst_new(124);
	// is_valid_args(stack_a, argc, argv);
	// // sort_list(stack_a);
	// ft_ra(&stack_a, false);
	ft_sa(stack_a, false);
	ft_sb(stack_b, false);
	ft_rra(&stack_a, false);
	ft_rrb(&stack_b, false);
	ft_ra(&stack_a, false);
	ft_rb(&stack_b, false);
	print_stack_list(stack_a);
	ft_printf("\n");
	print_stack_list(stack_b);
	free_stack_list(stack_b);
	free_stack_list(stack_a);
	// ft_ra(&stack_a, false);
	// print_stack_list(stack_a);
	// free(stack_b);
	// exit_handler(stack_a, NULL, 0);
}
