/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:44:08 by albillie          #+#    #+#             */
/*   Updated: 2024/12/06 13:46:23 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	args_checker(t_parsed *parsed, int argc, char **argv)
{
	int	i;

	if (argc < 2)
		ft_printf("Error\n"), exit(1);
	i = 0;
	if (argc == 2)
	{
		count_args(argv[1]);
		get_numbers(parsed, argv[1]);
	}
	i = 1;
	if (argc > 2)
	{
		while (i < argc)
		{
			if (!check_chars(argv[i]))
				ft_printf("Error\n"), exit(1);
			i++;
		}
	}
}

bool	check_chars(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			return (false);
		}
		i++;
	}
	return (true);
}


int	count_args(char *str)
{
	int		i;
	int		args;

	i = 0;
	args = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]))
		{
			i++;
		}
		if (str[i])
		{
			args++;
		}
		while (str[i] && !ft_isspace(str[i]))
		{
			i++;
		}
	}
	return (args);
}

void	get_numbers(t_parsed *parsed, char *str)
{
	char	**array;
	int		i;

	(void) parsed;
	array = ft_split(str, ' ');
	if (!array)
		ft_printf("Error\n"), exit(1);
	i = 0;
	while (array[i])
	{
		if (!check_chars(array[i]))
			ft_printf("Error\n"), free_array(array), exit(1);
		int number = ft_atoi(array[i]);
		printf("%d", number);
		insert_integers(&parsed, number);
		printf("\n%d\n", parsed->numbers);
		i++;
	}
	free_array(array);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		free(array[i++]);
	}
	free(array);
}

void	insert_integers(t_parsed **head, int nb)
{
	t_parsed *temp;
	temp = malloc(sizeof(t_parsed));
	temp->numbers = nb;
	temp->next = *head;
	*head = temp;
}

void	check_doubles(t_parsed *parsed)

/* void	check_double(t_parsed *parsed)
{
} */
