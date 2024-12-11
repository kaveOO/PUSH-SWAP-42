/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:08:28 by albillie          #+#    #+#             */
/*   Updated: 2024/12/11 08:08:41 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_when_string(t_parsed *parsed, char *str)
{
	split_and_fill(parsed, str);
	check_limits(parsed);
	check_doubles(parsed);
	print_numbers(parsed);
}
void	check_limits(t_parsed *parsed)
{
	int i = 0;
	while (parsed->array[i])
	{
		if (parsed->array[i] > INT_MAX || parsed->array[i] < INT_MIN)
			write_error();
		i++;
	}
}

void	split_and_fill(t_parsed *parsed, char *str)
{
	char	**array;
	int		i;

	array = ft_split(str, ' ');
	if (!array)
		ft_printf("test"),write_error();
	if (!array[1])
		free(parsed), free_array(array), write_error();
	parsed->array = malloc(sizeof(int) * (count_args(str)));
	i = 0;
	while (array[i])
	{
		if (!check_chars(array[i]))
			write_error();
		parsed->array[i] = ft_atol(array[i]);
		i++;
	}
}

void	print_numbers(t_parsed *parsed)
{
	int i = 0;
	while (parsed->array[i])
	{
		ft_printf("%d\n", parsed->array[i]);
		i++;
	}
}

void	check_doubles(t_parsed *parsed)
{
	int	i;
	int	j;

	i = 0;
	while (parsed->array[i])
	{
		j = i + 1;
		while (parsed->array[j])
		{
			if (parsed->array[j] ==  parsed->array[i])
			{
				ft_printf("Error\n"), free(parsed->array), free(parsed), exit(1);
			}
			j++;
		}
		i++;
	}
}
