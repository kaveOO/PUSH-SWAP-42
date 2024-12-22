/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:25:34 by albillie          #+#    #+#             */
/*   Updated: 2024/12/22 17:37:36 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_handler(t_stacks *stack_a, t_stacks *stack_b, int i)
{
	if (stack_a != NULL)
		free_stack_list(stack_a);
	if (stack_b != NULL)
		free_stack_list(stack_b);
	if (i == 1)
	{
		write(2, "Error\n", 6);
	}
	exit(1);
}
