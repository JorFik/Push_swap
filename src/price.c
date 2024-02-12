/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   price.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:33:29 by JFikents          #+#    #+#             */
/*   Updated: 2024/02/11 18:59:16 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
		Loop while both stacks can move to the top of the stack at the same
	time, indicating that a single operation like 'ss', 'rr', or 'rrr' can be
	applied to both. This allows a discount of 1 from the price. The loop
	continues until 'i' is equal or bigger than half of any of the stacks and
	neither stack's index has reached the top of the stack.
!		Maybe there is a problem because of the mismatch of >= and <= in
!	comparison with set_price function. Shouldn't be a problem, because for the
!	middle of the stack is irrelevant if it moves from the top or from the
!	bottom.
*/
static void	get_discount(t_stack_node *stack, t_stack_node *top,
	const int max_index_a, const int max_index_b)
{
	int			i;
	const int	half_a = max_index_a / 2;
	const int	half_b = max_index_b / 2;

	i = -1;
	while (((half_a >= stack->index + ++i && half_b >= top->index + i)
			|| (half_a <= stack->index - i && half_b <= top->index - i)
			|| max_index_a - stack->index == max_index_b - top->index)
		&& i < half_a && i < half_b && stack->index != max_index_a
		&& top->index != max_index_b && ((stack->index == 0 && top->index == 0)
			|| (stack->index != 0 && top->index != 0)))
		stack->price --;
}

t_stack_node	*find_closest_biggest(t_stack_node *stack,
	const int max_index_a)
{
	t_stack_node	*top_match;
	t_stack_node	*stack_b;
	const int		big_num_b = get_biggest_num(&(stack_bottom(stack))[B]);
	const int		tiny_num_b = get_smallest_num(&(stack_bottom(stack))[B]);

	stack_b = &(stack_bottom(stack))[B];
	top_match = stack_b;
	while (top_match->num != tiny_num_b)
		top_match = top_match->next;
	while (stack_b)
	{
		if ((stack->num > stack_b->num && top_match->num < stack_b->num)
			|| (stack->num < tiny_num_b && stack_b->num == big_num_b))
			top_match = stack_b;
		stack_b = stack_b->next;
	}
	return (top_match);
}

/*
		It is stack->index + 1 or/and top->index + 1 because it is on the bottom
	half of the stack so it need an extra operation to reach the top.
?	half_a is > stack->index when stack is below the middle of stack A
?	half_a is <= stack->index when stack is above the middle of stack A
?	half_b is <= top->index when top is above the middle of stack B
?	half_b is > top->index when top is below the middle of stack B
?	< or > having the = sign is irrelevant because the price is the same anyway,
?		so it's an arbitrary choice.
*/
void	set_price(t_stack_node *stack)
{
	t_stack_node	*top_match;
	const int		max_index_a = stack_top(stack)->index;
	const int		max_index_b = stack_top(&stack[B])->index;
	const int		half_a = max_index_a / 2;
	const int		half_b = max_index_b / 2;

	while (stack)
	{
		top_match = find_closest_biggest(stack, max_index_a);
		if (half_a > stack->index && half_b <= top_match->index)
			stack->price = stack->index + 1 + max_index_b - top_match->index;
		if (half_a > stack->index && half_b > top_match->index)
			stack->price = stack->index + 1 + top_match->index + 1;
		if (half_a <= stack->index && half_b <= top_match->index)
			stack->price = max_index_a - stack->index + max_index_b
				- top_match->index;
		if (half_a <= stack->index && half_b > top_match->index)
			stack->price = max_index_a - stack->index + top_match->index + 1;
		get_discount(stack, top_match, max_index_a, max_index_b);
		stack = stack->next;
	}
}
