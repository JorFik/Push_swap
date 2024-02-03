/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:36:03 by JFikents          #+#    #+#             */
/*   Updated: 2024/02/03 13:52:18 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*stack_last(t_stack_node *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack_node	*stack_first(t_stack_node *stack)
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
	last = stack_last(stack);
	last->next = node;
	node->num = num;
	node->index = last->index + 1;
	node->goal = START_INDEX - 1;
	node->price = 0;
	node->prev = last;
}
