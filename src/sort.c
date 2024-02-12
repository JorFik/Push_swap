/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:09:37 by JFikents          #+#    #+#             */
/*   Updated: 2024/02/12 16:38:09 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_in_order(t_stack_node *stack)
{
	const int		half_a = stack_top(stack)->index / 2;
	const int		smallest = get_smallest_num(stack);
	t_stack_node	*small_node;

	small_node = stack;
	while (small_node->num != smallest)
		small_node = small_node->next;
	if (small_node->index >= half_a)
		while (stack_top(stack)->num != smallest)
			move(stack, RA);
	else if (small_node->index < half_a)
		while (stack_top(stack)->num != smallest)
			move(stack, RRA);
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
	while (stack->next)
	{
		set_price(stack);
		find_moves(stack);
		move(stack, PB);
	}
	set_price(stack);
	find_moves(stack);
	while (stack[B].index != -1)
		move(stack, PA);
	put_in_order(stack);
}
