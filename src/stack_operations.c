/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:36:03 by JFikents          #+#    #+#             */
/*   Updated: 2024/02/13 20:27:22 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*stack_top(t_stack_node *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack_node	*stack_bottom(t_stack_node *stack)
{
	while (stack->prev)
		stack = stack->prev;
	return (stack);
}

void	add_node(t_stack_node *stack, int num)
{
	t_stack_node	*last;
	t_stack_node	*node;

	node = ft_calloc(1, sizeof(t_stack_node));
	exit_on_error((int [3]){IF_NULL, MALLOC_FAIL, N_NODE}, node, NULL);
	last = stack_top(stack);
	last->next = node;
	node->num = num;
	node->index = last->index + 1;
	node->goal = START_INDEX - 1;
	node->price = -1;
	node->free = 1;
	node->moves = NULL;
	node->prev = last;
	node->next = NULL;
}

void	del_node(t_stack_node *stack)
{
	stack = stack_top(stack);
	if (stack->prev)
		stack->prev->next = NULL;
	ft_free_n_null((void **)&stack);
}

void	swap_stacks(t_stack_node *stack)
{
	stack[A].num = stack[A].num ^ stack[B].num;
	stack[B].num = stack[A].num ^ stack[B].num;
	stack[A].num = stack[A].num ^ stack[B].num;
	stack[A].goal = stack[A].goal ^ stack[B].goal;
	stack[B].goal = stack[A].goal ^ stack[B].goal;
	stack[A].goal = stack[A].goal ^ stack[B].goal;
	stack[A].price = stack[A].price ^ stack[B].price;
	stack[B].price = stack[A].price ^ stack[B].price;
	stack[A].price = stack[A].price ^ stack[B].price;
	stack[A].next = (t_stack_node *)((long)stack[A].next ^ (long)stack[B].next);
	stack[B].next = (t_stack_node *)((long)stack[A].next ^ (long)stack[B].next);
	stack[A].next = (t_stack_node *)((long)stack[A].next ^ (long)stack[B].next);
	if (stack[A].next && stack[B].next)
	{
		stack[A].next->prev = (t_stack_node *)((long)stack[A].next->prev
				^ (long)stack[B].next->prev);
		stack[B].next->prev = (t_stack_node *)((long)stack[A].next->prev
				^ (long)stack[B].next->prev);
		stack[A].next->prev = (t_stack_node *)((long)stack[A].next->prev
				^ (long)stack[B].next->prev);
	}
	else if (stack[B].next)
		stack[B].next->prev = &stack[B];
	else if (stack[A].next)
		stack[A].next->prev = &stack[A];
}
