/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:25:34 by albillie          #+#    #+#             */
/*   Updated: 2024/12/28 10:45:46 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_handler(t_stacks *sa, t_stacks *sb, t_chunks *chunks, int i)
{
	if (chunks)
		free_chunks_list(chunks);
	if (sa)
		free_stack_list(sa);
	if (sb)
		free_stack_list(sb);
	if (i == 1)
		write(2, "Error\n", 6);
	exit(1);
}
