/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:09:37 by JFikents          #+#    #+#             */
/*   Updated: 2024/02/13 21:21:05 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	sort_3(t_stack_node *stack, int exit)
{
	if (stack_top(stack)->index > 2)
		return ;
	if (!check_order_a(stack))
		move(stack, SA);
	put_small_on_top(stack);
	if (exit)
		exit_on_error((int [3]){SUCCESS, 0, 0}, NULL, stack);
}

static void	sort_5(t_stack_node *stack)
{
	int				match;

	if (stack_top(stack)->index > 4)
		return ;
	move(stack, PB);
	move(stack, PB);
	restart_goal(stack);
	if (!check_order_a(stack))
		move(stack, SA);
	swap_stacks(stack);
	match = find_closest_biggest(stack->next, stack_top(stack)->index)->num;
	swap_stacks(stack);
	while (stack_bottom(stack)->num != match)
		move(stack, RA);
	move(stack, PA);
	swap_stacks(stack);
	match = find_closest_biggest(stack, stack_top(stack)->index)->num;
	swap_stacks(stack);
	while (stack_bottom(stack)->num != match)
		move(stack, RA);
	move(stack, PA);
	put_small_on_top(stack);
	exit_on_error((int [3]){SUCCESS, 0, 0}, NULL, stack);
}

static void	push_back(t_stack_node *stack)
{
	int				match;
	int				index;

	while (stack[B].index != -1)
	{
		swap_stacks(stack);
		match = find_closest_biggest(stack_top(stack),
				stack_top(stack)->index)->num;
		index = find_closest_biggest(stack_top(stack),
				stack_top(stack)->index)->index;
		swap_stacks(stack);
		while (stack_bottom(stack)->num != match && stack_top(stack)->index / 2
			>= index)
			move(stack, RA);
		while (stack_bottom(stack)->num != match && stack_top(stack)->index / 2
			> index)
			move(stack, RRA);
		move(stack, PA);
	}
}

void	sort(t_stack_node *stack)
{
	sort_3(stack, EXIT);
	sort_5(stack);
	move(stack, PB);
	move(stack, PB);
	move(stack, PB);
	restart_goal(stack);
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
