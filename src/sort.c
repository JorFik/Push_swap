/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:09:37 by JFikents          #+#    #+#             */
/*   Updated: 2024/02/10 19:57:21 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (stack->price < cheapest->price || (stack->price == cheapest->price
				&& ((top_match->num == big_num_b && stack->num > cheapest->num)
					|| stack->num < cheapest->num)))
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
	// find_moves(stack);
	ft_printf("cheapest: %d\n", get_cheapest(stack)->num);
	print_stack(stack);
	print_stack(&stack[B]);
}
