/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:14:48 by JFikents          #+#    #+#             */
/*   Updated: 2024/02/12 16:38:51 by JFikents         ###   ########.fr       */
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
	stack[A].num = 0;
	stack[A].index = START_INDEX - 1;
	stack[A].goal = -1;
	stack[A].price = -1;
	stack[A].free = 0;
	stack[A].next = NULL;
	stack[A].prev = NULL;
	stack[B].num = 0;
	stack[B].index = START_INDEX - 1;
	stack[B].goal = -1;
	stack[B].price = -1;
	stack[B].free = 0;
	stack[B].next = NULL;
	stack[B].prev = NULL;
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
