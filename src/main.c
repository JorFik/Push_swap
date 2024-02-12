/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:14:48 by JFikents          #+#    #+#             */
/*   Updated: 2024/02/12 20:24:39 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	read_args(int argc, char **argv, t_stack_node stack[2])
{
	int	split;

	split = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		exit_on_error((int [3]){IF_NULL, MALLOC_FAIL, READ_ARGS}, argv, stack);
		split = 1;
		argc = 0;
		while (argv[argc])
			argc++;
	}
	check_arg(argv[--argc], stack);
	stack[A].num = ft_atoi(argv[argc--]);
	stack[A].index ++;
	while ((argc == 0 && split == 1) || argc > 0)
	{
		check_arg(argv[argc], stack);
		add_node(&stack[A], ft_atoi(argv[argc--]));
	}
	if (split == 1)
		ft_free_2d_array((void ***)&argv, -1);
}

static void	initialize_stack(t_stack_node stack[2])
{
	enum e_stacks	i;

	i = A;
	while (i <= B)
	{
		stack[i].num = 0;
		stack[i].index = START_INDEX - 1;
		stack[i].goal = -1;
		stack[i].price = -1;
		stack[i].free = 0;
		stack[i].moves = NULL;
		stack[i].next = NULL;
		stack[i].prev = NULL;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	stack[2];

	if (argc < 2)
		return (NO_ARG);
	initialize_stack(stack);
	read_args(argc, argv, stack);
	set_goal_a(stack);
	check_stack(stack, EXIT);
	sort(stack);
	do_moves(stack);
	exit_on_error((int [3]){SUCCESS, 0, 0}, NULL, stack);
}

//? * ------------------------ ALLOWED FUNCTIONS ------------------------ * ?//
/* 
	ssize_t	read(file_descriptor, buffer, count);
	ssize_t	write(file_descriptor, buffer, count);
	void	*malloc(size_t size);
	void	free(void *ptr);
	void	exit(int status);
 */
//_--------------------------------------------------------------------------_//
