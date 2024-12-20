/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:12:44 by albillie          #+#    #+#             */
/*   Updated: 2024/12/20 17:57:22 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_chars(t_stacks *stack_a, int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
		{
			j++;
			if (!ft_isdigit(av[i][j]))
				exit_handler(stack_a, 1);
			j++;
		}
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				exit_handler(stack_a, 1);
			j++;
		}
		i++;
	}
}
void	check_len(t_stacks *stack_a, int ac, char **av)
{
	int i;
	size_t j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] == '+' || av[i][j] == '-' || av[i][j] == '0')
			j++;
		while (ft_isdigit(av[i][j]))
			j++;
		if (j > ft_strlen("9223372036854775807"))
			exit_handler(stack_a, 1);
		i++;
	}
}

void	check_limits(t_stacks *stack_a, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN)
			exit_handler(stack_a, 1);
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
			if (temp->next->data == current->data)
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
		if (ptr->data > ptr->next->data)
			return;
		ptr = ptr->next;
	}
	exit_handler(stack_a, 0);
}

