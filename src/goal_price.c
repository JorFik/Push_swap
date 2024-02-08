/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goal_price.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:01:27 by JFikents          #+#    #+#             */
/*   Updated: 2024/02/08 13:12:08 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	restart_goal(t_stack_node *stack)
{
	stack = stack_bottom(stack);
	while (stack)
	{
		stack->goal = START_INDEX - 1;
		stack = stack->next;
	}
}

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

static	t_stack_node	*find_closest_biggest(t_stack_node *stack)
{
	t_stack_node			*stack_b;
	t_stack_node			*top;
	const int				big_b = get_biggest(&(stack_bottom(stack))[B]);
	const int				max_index_a = stack_top(stack)->index;

	stack_b = &(stack_bottom(stack))[B];
	top = stack_b;
	while (stack_b->next)
	{
		if ((stack->num > stack_b->num && top->num < stack_b->num)
			|| (stack->goal == max_index_a && stack_b->num == big_b))
			top = stack_b;
		stack_b = stack_b->next;
	}
	if ((stack->num > stack_b->num && top->num < stack_b->num)
		|| (stack->goal == max_index_a && stack_b->num == big_b))
		top = stack_b;
	return (top);
}

// ? half_a is >= stack->index when stack is below the middle of stack A
// ? half_a is < stack->index when stack is above the middle of stack A
// ? half_b is < top->index when top is above the middle of stack B
// ? half_b is >= top->index when top is below the middle of stack B
void	set_price(t_stack_node *stack)
{
	t_stack_node			*top;
	int						i;
	const int				max_index_b = stack_top(&stack[B])->index;
	const int				half_a = stack_top(stack)->index / 2;
	const int				half_b = max_index_b / 2;

	while (stack)
	{
		top = find_closest_biggest(stack);
		if (half_a >= stack->index && half_b < top->index)
			stack->price = stack->index + max_index_b - top->index + 1;
		if (half_a >= stack->index && half_b >= top->index)
			stack->price = stack->index + top->index + 2;
		if (half_a < stack->index && half_b < top->index)
			stack->price = stack_top(stack)->index - stack->index + max_index_b
				- top->index;
		if (half_a < stack->index && half_b >= top->index)
			stack->price = stack_top(stack)->index - stack->index + top->index
				+ 1;
		i = -1;
		while (((half_a >= stack->index + ++i && half_b >= top->index + i)
				|| (half_a < stack->index - i && half_b < top->index - i))
			&& i < half_a && i < half_b && stack->price > 0)
			stack->price --;
		stack = stack->next;
	}
}
