/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:01:27 by JFikents          #+#    #+#             */
/*   Updated: 2024/02/13 17:47:10 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	restart_goal(t_stack_node *stack)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = stack_bottom(stack);
	stack_b = &stack[B];
	while (stack_a)
	{
		stack_a->goal = START_INDEX - 1;
		stack_a = stack_a->next;
	}
	while (stack_b)
	{
		stack_b->goal = START_INDEX - 1;
		stack_b = stack_b->next;
	}
	set_goal_a(stack);
	set_goal_b(&stack[B]);
}
	// stack = stack_bottom(stack);
	// while (stack)
	// {
	// 	stack->goal = START_INDEX - 1;
	// 	stack = stack->next;
	// }

void	set_goal_a(t_stack_node *stack)
{
	t_stack_node	*next_top;
	static int		index = START_INDEX;

	next_top = stack;
	while (stack)
	{
		if ((stack->num > next_top->num && stack->goal == START_INDEX - 1)
			|| next_top->goal != START_INDEX - 1)
			next_top = stack;
		stack = stack->next;
	}
	if (next_top->goal == START_INDEX - 1)
	{
		next_top->goal = index++;
		set_goal_a(stack_bottom(next_top));
	}
	index = START_INDEX;
}

void	set_goal_b(t_stack_node *stack)
{
	t_stack_node	*next_low;
	static int		index = START_INDEX;

	next_low = stack;
	while (stack)
	{
		if ((stack->num < next_low->num && stack->goal == START_INDEX - 1)
			|| next_low->goal != START_INDEX - 1)
			next_low = stack;
		stack = stack->next;
	}
	if (next_low->goal == START_INDEX - 1)
	{
		next_low->goal = index++;
		set_goal_b(stack_bottom(next_low));
	}
	index = START_INDEX;
}
