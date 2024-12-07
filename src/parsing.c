/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:44:08 by albillie          #+#    #+#             */
/*   Updated: 2024/12/07 06:56:59 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	args_checker(t_parsed *parsed, int argc, char **argv)
{
	int	i;

	if (argc == 0)
	{
		exit(1);
	}
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
		insert_integers(number);
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

/* struct *create_elem(int nb)
{

}

void	add_elem(stack)
{
	create_elem(num);
	while()
	{
	}
	stack
} */

void	insert_integers(int nb)
{
	int	array[10];
	int	i;
	i = 0;

	while (array[i])
	{
		array[i] = nb;
		i++;
	}
	printf("%d\n", array[1]);
}


/* void	check_doubles(t_parsed *parsed)
{
	int i = 0;

	while (parsed->numbers[i])
	{
		printf("%d", parsed->numbers);
		i++;
	}
} */

/* void	check_double(t_parsed *parsed)
{
} */
