/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:48:02 by albillie          #+#    #+#             */
/*   Updated: 2024/12/29 22:28:14 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <libft.h>
# include <limits.h>

typedef struct s_chunks
{
	int					*array;
	int					chunks_count;
	int					middle;
	int 				offset;
	int 				start;
	int 				end;
	int					size;
}						t_chunks;

typedef struct s_mimax
{
	int					min;
	int					index;
	int					max;
}						t_mimax;


typedef struct s_stacks
{
	int					data;
	struct s_stacks		*next;
}						t_stacks;

// ? INIT FUNCTIONS

t_stacks	*init_stack_a(int ac, char **av);
t_chunks	*init_chunks_stack(t_stacks **stack_a);
t_mimax		*init_mimax();

// ? PARSING FUNCTIONS

bool		is_valid_args(t_stacks *stack_a, int ac, char **av);
bool		check_chars(int ac, char **av);
bool		check_limits(int ac, char **av);
bool		check_len(int ac, char **av);
bool		check_for_doubles(t_stacks *list);
bool		check_if_sorted(t_stacks *stack_a);

// ? LISTS FUNCTIONS

t_stacks	*stack_lst_new(int data);
void		stack_add_back(t_stacks **list, t_stacks *data);
void		print_stack_list(t_stacks *list);
void		free_stack_list(t_stacks *list);
int			get_list_size(t_stacks *stack);
void		stack_add_front(t_stacks **stack, t_stacks *data);

// ? HANDLING UTILS FUNCTIONS

void	exit_handler(t_stacks *sa, t_stacks *sb, t_chunks *chunks, int i);

// ? CHUNKS UTILS

int		get_chunks_count(int lst_size);
void	free_chunks_list(t_chunks *chunks);
int		get_array_size(int *array);
int		get_element_pos(t_chunks *chunks, int data);
void	update_chunks_pos(t_chunks *chunks, t_stacks **stack_a);
bool	elements_in_chunks(t_chunks *chunks, t_stacks **stack_a);
void	push_to_a(t_stacks **sa, t_stacks **sb, t_chunks *chks, t_mimax *mimax);
int		find_bigger(t_stacks **stack_b, t_mimax **mimax);



// ? SORTING FUNCTIONS

void	sort_list(t_stacks **sa, t_stacks **sb, t_chunks *chks, t_mimax *mimax);
void	sort_3_digits(t_stacks **stack_a);
void	chunk_sort(t_stacks **sa, t_stacks **sb, t_chunks *chunks);
int		*fill_sort_array(t_stacks **stack_a);
void	print_array(int *array);
int		*bubble_sort_array(int *array);


// ? INSTRUCTIONS

void	ft_sa(t_stacks *stack_a, bool both);
void	ft_sb(t_stacks *stack_b, bool both);
void	ft_ss(t_stacks *stack_a, t_stacks *stack_b);
void	ft_pa(t_stacks **stack_a, t_stacks **stack_b);
void	ft_pb(t_stacks **stack_b, t_stacks **stack_a);
void	ft_ra(t_stacks **stack_a, bool both);
void	ft_rb(t_stacks **stack_b, bool both);
void	ft_rr(t_stacks **stack_a, t_stacks **stack_b);
void	ft_rra(t_stacks **stack_a, bool both);
void	ft_rrb(t_stacks **stack_b, bool both);
void	ft_rrr(t_stacks **stack_a, t_stacks **stack_b);

#endif
