/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:20:16 by kaveo             #+#    #+#             */
/*   Updated: 2024/12/20 18:59:08 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_digits(t_stacks *stack_a)
{
	stack_a->temp = stack_a->data;
	stack_a->data = stack_a->next->data;
	stack_a->next->data = stack_a->temp;
	// ft_printf("%d %d", stack_a->data, stack_a->next->data);
	ft_printf("sa\n");
}

