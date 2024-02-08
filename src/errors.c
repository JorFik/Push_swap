/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:14:05 by JFikents          #+#    #+#             */
/*   Updated: 2024/02/06 13:42:47 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_error(int error)
{
	if (error == MALLOC_FAIL)
		return ("Malloc error");
	if (error == READ_FAIL)
		return ("Read error");
	if (error == FREE_FAIL)
		return ("Free error");
	if (error == WRITE_FAIL)
		return ("Write error");
	if (error == DUPLICATE)
		return ("Duplicate number");
	if (error == NO_INT)
		return ("Other characters than integers");
	if (error == OUTSIDE_INT)
		return ("Number is outside the integer range");
	return ("Unknown error");
}

static char	*where(int where)
{
	if (where == STACK_A)
		return ("in stack A");
	if (where == STACK_B)
		return ("in stack B");
	if (where == ARG)
		return ("in the given arguments");
	if (where == READ_ARGS)
		return ("while reading the arguments");
	if (where == N_NODE)
		return ("while creating a new node");
	return ("in unknown location");
}

static void	free_stacks(t_stack_node stacks[2])
{
	t_stack_node	*stack;
	t_stack_node	*tmp;
	t_stack_node	*b;

	stack = stack_bottom(&stacks[A]);
	b = stack_bottom(&stacks[B]);
	while (stack->next)
	{
		tmp = stack->next;
		stack->next = stack->next->next;
		if (tmp->free)
			ft_free_n_null((void **)&tmp);
	}
	while (b->next)
	{
		tmp = b->next;
		b->next = b->next->next;
		if (tmp->free)
			ft_free_n_null((void **)&tmp);
	}
}

void	exit_on_error(int check[3], void *if_null, t_stack_node stacks[2])
{
	if (check[STATE] == -1 || (check[STATE] == IF_NULL && !if_null))
	{
		write(STDERR_FILENO, "Error\n", 7);
		ft_printf("%s %s\n", get_error(check[ERROR]), where(check[WHERE]));
		free_stacks(stacks);
		exit(check[ERROR]);
	}
	if (check[STATE] == SUCCESS)
	{
		free_stacks(stacks);
		exit(0);
	}
}
