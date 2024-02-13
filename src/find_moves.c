/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:38:02 by JFikents          #+#    #+#             */
/*   Updated: 2024/02/13 20:12:35 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_to_top(t_stack_node *stack, const t_stack_node *cheap_node,
		const t_stack_node *top_node)
{
	const int		cheap_num = cheap_node->num;
	const int		top_num = top_node->num;
	const int		half_a = stack_top(stack)->index / 2;
	const int		half_b = stack_top(&stack[B])->index / 2;
	int				distance;

	distance = stack_top(stack)->index - cheap_node->index;
	if (cheap_node->index < half_a)
		distance = cheap_node->index + 1;
	if (cheap_node->index >= half_a)
		while (distance--)
			add_move(stack, RA);
	else if (cheap_node->index < half_a)
		while (distance--)
			add_move(stack, RRA);
	distance = stack_top(&stack[B])->index - top_node->index;
	if (top_node->index < half_b)
		distance = top_node->index + 1;
	if (top_node->index >= half_b)
		while (distance--)
			add_move(stack, RB);
	else if (top_node->index < half_b)
		while (distance--)
			add_move(stack, RRB);
	do_moves(stack);
}

//	_This comment is not relevant anymore
//	This 'if' checks two main conditions:
//	1. If current stack's price is less than the cheapest one found so far.
//									OR
//	2. If current stack's price equals the cheapest:
//									AND
//		a. If top_match's num equals big_num_b and current stack's num is
//			greater than cheapest's num. This condition has priority that's why
//			it's checked first.
//								OR	AND
//		b. If current stack's num is less than cheapest's num.
//	If any of these conditions is true, the cheapest is updated to the current
//	stack node.
static t_stack_node	*get_cheapest(t_stack_node *stack)
{
	t_stack_node	*cheapest;
	const int		big_num_b = get_biggest_num(&(stack_bottom(stack))[B]);
	t_stack_node	*top_match;

	stack = stack_top(stack);
	cheapest = stack;
	while (stack)
	{
		top_match = find_closest_biggest(stack, stack_top(stack)->index);
		if (stack->price < cheapest->price)
			cheapest = stack;
		stack = stack->prev;
	}
	return (cheapest);
}

void	find_moves(t_stack_node *stack)
{
	t_stack_node	*cheapest;
	t_stack_node	*top_match;

	cheapest = get_cheapest(stack);
	top_match = find_closest_biggest(cheapest, stack_top(stack)->index);
	move_to_top(stack, cheapest, top_match);
}
