/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:12:44 by albillie          #+#    #+#             */
/*   Updated: 2024/12/20 08:59:41 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_chars(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (!ft_isdigit(str[i]))
			exit_handler(NULL, 1);
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			exit_handler(NULL, 1);
		i++;
	}
}

void	check_for_doubles(t_stacks *list)
{
	t_stacks *current;
	t_stacks *temp;

	current = list;
	while (current)
	{
		temp = current;
		while (temp->next)
		{
			if (temp->next->stack_a == current->stack_a)
				exit_handler(list, 1);
			temp = temp->next;
		}
		current = current->next;
	}
}

void	check_if_sorted(t_stacks *stack_a)
{
	t_stacks	*ptr;

	ptr = stack_a;
	while (ptr->next != NULL)
	{
		if (ptr->stack_a > ptr->next->stack_a)
			return;
		ptr = ptr->next;
	}
	exit_handler(stack_a, 0);
}

void	check_len(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == '+' || str[i] == '-' || str[i] == '0')
		str++;
	while (ft_isdigit(str[i]))
		i++;
	if (i > ft_strlen("9223372036854775807"))
		exit_handler(NULL, 1);
}

void	check_limits(char *str)
{
	if (ft_atol(str) > INT_MAX || ft_atol(str) < INT_MIN)
		exit_handler(NULL, 1);
}
