/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:38:02 by JFikents          #+#    #+#             */
/*   Updated: 2024/02/12 20:38:48 by JFikents         ###   ########.fr       */
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

	if (cheap_node->index >= half_a)
		while (stack_top(stack)->num != cheap_num)
			move(stack, RA);
	else if (cheap_node->index < half_a)
		while (stack_top(stack)->num != cheap_num)
			move(stack, RRA);
	if (top_node->index >= half_b)
		while (stack_top(&stack[B])->num != top_num)
			move(stack, RB);
	else if (top_node->index < half_b)
		while (stack_top(&stack[B])->num != top_num)
			move(stack, RRB);
}

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
// ! Aparenttly this is making it worse, so I'll comment it out for now.
			// || (stack->price == cheapest->price
			// 	&& ((top_match->num == big_num_b && stack->num > cheapest->num)
			// 		|| stack->num < cheapest->num)))
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

/*
		Uses either 'RR' or 'RRR' operation to move both stacks to the top of the
	stack, taking into account the discount conditions. If `max_index_a` -
	`stack->index` equals `max_index_b` - `top->index`, we use the bigger half
	of the stack to know if we should move the stack using 'RR' or 'RRR'.
		Else, we check if we can move both to the top of the stack using the
	same operation, even if the stacks are not at the same distance.
*/
static void	discount_moves(t_stack_node *stack, t_stack_node *top,
	const int max_index_a, const int max_index_b)
{
	int			i;
	const int	half_a = max_index_a / 2;
	const int	half_b = max_index_b / 2;
	int			relative_index_a;
	int			relative_index_b;

	i = -1;
	relative_index_a = max_index_a - stack->index;
	relative_index_b = max_index_b - top->index;
	while (++i && stack->index != max_index_a
		&& top->index != max_index_b && relative_index_a == relative_index_b)
	{
		relative_index_a = max_index_a - stack->index;
		relative_index_b = max_index_b - top->index;
		if (relative_index_a > half_a)
			move(stack, RRR);
		if (relative_index_a <= half_a)
			move(stack, RR);
	}
}

void	find_moves(t_stack_node *stack)
{
	t_stack_node	*cheapest;
	t_stack_node	*top_match;

	cheapest = get_cheapest(stack);
	top_match = find_closest_biggest(cheapest, stack_top(stack)->index);
	discount_moves((t_stack_node *)cheapest, (t_stack_node *)top_match,
		stack_top(stack)->index, stack_top(&stack[B])->index);
	set_price(stack);
	cheapest = get_cheapest(stack);
	top_match = find_closest_biggest(cheapest, stack_top(stack)->index);
	move_to_top(stack, cheapest, top_match);
}
