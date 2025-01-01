/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:12:44 by albillie          #+#    #+#             */
/*   Updated: 2025/01/01 14:15:52 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_chars(int ac, char **av)
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
				return (false);
			j++;
		}
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_len(int ac, char **av)
{
	int		i;
	size_t	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] == '+' || av[i][j] == '-' || av[i][j] == '0')
			j++;
		while (ft_isdigit(av[i][j]))
			j++;
		if (j > ft_strlen("9223372036854775807"))
			return (false);
		i++;
	}
	return (true);
}

bool	check_limits(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN)
			return (false);
		i++;
	}
	return (true);
}

bool	check_for_doubles(t_stacks *list)
{
	t_stacks	*current;
	t_stacks	*temp;

	current = list;
	while (current)
	{
		temp = current;
		while (temp->next)
		{
			if (temp->next->data == current->data)
				return (false);
			temp = temp->next;
		}
		current = current->next;
	}
	return (true);
}

bool	check_if_sorted(t_stacks *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->data > stack_a->next->data)
		{
			return (false);
		}
		stack_a = stack_a->next;
	}
	return (true);
}
