/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:09:49 by JFikents          #+#    #+#             */
/*   Updated: 2024/02/12 19:20:27 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_biggest_num(t_stack_node *stack)
{
	int	biggest_num;

	biggest_num = stack->num;
	while (stack)
	{
		if (stack->num > biggest_num)
			biggest_num = stack->num;
		stack = stack->next;
	}
	return (biggest_num);
}

int	get_smallest_num(t_stack_node *stack)
{
	int	smallest_num;

	smallest_num = stack->num;
	while (stack)
	{
		if (stack->num < smallest_num)
			smallest_num = stack->num;
		stack = stack->next;
	}
	return (smallest_num);
}

int	check_order_b(t_stack_node *stack)
{
	const int	biggest = get_biggest_num(stack);

	stack = stack_bottom(stack);
	while (stack->next)
	{
		if ((stack->goal > stack->next->goal && stack->num != biggest)
			|| (stack->next->goal != START_INDEX && stack->num == biggest))
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	check_order_a(t_stack_node *stack)
{
	const int	smallest = get_smallest_num(stack);

	stack = stack_bottom(stack);
	while (stack->next)
	{
		if ((stack->goal < stack->next->goal && stack->num != smallest)
			|| (stack->next->goal == START_INDEX && stack->num == smallest))
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	check_stack(t_stack_node *stack, int exit)
{
	stack = stack_bottom(stack);
	while (stack->next)
	{
		if (stack->goal != stack->index)
			return (0);
		stack = stack->next;
	}
	if (stack->goal != stack->index)
		return (0);
	if (exit)
		exit_on_error((int [3]){SUCCESS, 0, 0}, NULL, stack_bottom(stack));
	return (1);
}
