/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:44:08 by albillie          #+#    #+#             */
/*   Updated: 2024/12/09 04:45:25 by albillie         ###   ########.fr       */
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
	return (args - 1);
}

void	get_numbers(t_parsed *parsed, char *str)
{
	char	**array;
	int		i;

	// printf("%d", count_args(str));
	parsed->array = malloc(sizeof(int) * (count_args(str)));
	array = ft_split(str, ' ');
	if (!array)
		ft_printf("Error\n"), exit(1);
	i = 0;
	while (array[i])
	{
		if (!check_chars(array[i]))
			ft_printf("Error\n"), free_array(array), exit(1);
		int number = ft_atoi(array[i]);
		parsed->array[i] = number;
		i++;
	}
	free_array(array);
	sort_array(parsed, str);
	print_numbers(parsed);
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

void	sort_array(t_parsed *parsed, char *str)
{
	int	i;
	int j;

	i = 0;
	while (i < count_args(str))
	{
		j = 0;
		bool swapped = true;
		while (swapped)
		{
			if (parsed->array[j] > pars	ed->array[j + 1])
			{
				ft_printf("%d is bigger than %d\n", parsed->array[j], parsed->array[j + 1]);
				swapped = true;
				j++;
			}
			j++;
		}
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

// void	add_elem(stack)
// {
// 	create_elem(num);
// 	while()
// 	{
// 	}
// 	stack
// }

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// void	sort_int_tab()
// {



// }



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
