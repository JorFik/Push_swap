/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:09:37 by JFikents          #+#    #+#             */
/*   Updated: 2024/02/12 20:15:19 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	swap_stacks(t_stack_node *stack)
// {
// 	stack[A].num = stack[A].num ^ stack[B].num;
// 	stack[B].num = stack[A].num ^ stack[B].num;
// 	stack[A].num = stack[A].num ^ stack[B].num;
// 	stack[A].goal = stack[A].goal ^ stack[B].goal;
// 	stack[B].goal = stack[A].goal ^ stack[B].goal;
// 	stack[A].goal = stack[A].goal ^ stack[B].goal;
// 	stack[A].price = stack[A].price ^ stack[B].price;
// 	stack[B].price = stack[A].price ^ stack[B].price;
// 	stack[A].price = stack[A].price ^ stack[B].price;
// 	stack[A].next = ((int)stack[A].next ^ (int)stack[B].next);
// 	stack[B].next = ((int)stack[A].next ^ (int)stack[B].next);
// 	stack[A].next = ((int)stack[A].next ^ (int)stack[B].next);
// }

static void	put_small_on_top(t_stack_node *stack)
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
	put_small_on_top(stack);
}
