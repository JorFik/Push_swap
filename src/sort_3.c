/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:09:37 by JFikents          #+#    #+#             */
/*   Updated: 2024/02/08 12:45:04 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_node	*get_cheapest(t_stack_node *stack)
{
	t_stack_node	*cheapest;

	stack = stack_top(stack);
	cheapest = stack;
	while (stack)
	{
		if (stack->price < cheapest->price)
			cheapest = stack;
		stack = stack->prev;
	}
	return (cheapest);
}

void	sort(t_stack_node *stack)
{
	move(stack, PB);
	move(stack, PB);
	move(stack, PB);
	restart_goal(&stack[B]);
	set_goal_b(&stack[B]);
	restart_goal(stack);
	set_goal_a(stack);
	if (!check_order_b(&stack[B]))
		move(stack, SB);
	set_price(stack);
	print_stack(stack);
	print_stack(&stack[B]);
}
