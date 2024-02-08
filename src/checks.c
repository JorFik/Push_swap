/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:09:49 by JFikents          #+#    #+#             */
/*   Updated: 2024/02/07 15:36:00 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_biggest(t_stack_node *stack)
{
	int	biggest;

	biggest = stack->num;
	while (stack)
	{
		if (stack->num > biggest)
			biggest = stack->num;
		stack = stack->next;
	}
	return (biggest);
}

int	check_order_b(t_stack_node *stack)
{
	const int	biggest = get_biggest(stack);

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
	const int	biggest = get_biggest(stack);

	stack = stack_bottom(stack);
	while (stack->next)
	{
		if ((stack->goal < stack->next->goal && stack->num != biggest)
			|| (stack->next->goal == START_INDEX && stack->num == biggest))
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
