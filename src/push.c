/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:12:32 by JFikents          #+#    #+#             */
/*   Updated: 2024/02/06 13:41:20 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack_node stack[2])
{
	t_stack_node	*b;

	b = stack_top(&stack[B]);
	stack = stack_top(stack);
	if (stack->index != START_INDEX - 1 && b->free)
	{
		stack->next = b;
		b->prev->next = NULL;
		b->prev = stack;
		b->index = stack->index + 1;
	}
	if (stack->index != START_INDEX - 1 && !b->free)
	{
		add_node(stack, b->num);
		stack->next->goal = b->goal;
		b->index = START_INDEX - 1;
	}
	if (stack->index == START_INDEX - 1 && b->free)
	{
		stack->num = b->num;
		stack->index = START_INDEX;
		stack->goal = b->goal;
		b->prev->next = NULL;
		ft_free_n_null((void **)&b);
	}
}

void	push_b(t_stack_node stack[2])
{
	t_stack_node	*a;

	a = stack_top(&stack[A]);
	stack = stack_top(&stack[B]);
	if (stack->index != START_INDEX - 1 && a->free)
	{
		stack->next = a;
		a->prev->next = NULL;
		a->prev = stack;
		a->index = stack->index + 1;
	}
	if (stack->index != START_INDEX - 1 && !a->free)
	{
		add_node(stack, a->num);
		stack->next->goal = a->goal;
		a->index = START_INDEX - 1;
	}
	if (stack->index == START_INDEX - 1 && a->free)
	{
		stack->num = a->num;
		stack->index = START_INDEX;
		stack->goal = a->goal;
		a->prev->next = NULL;
		ft_free_n_null((void **)&a);
	}
}
