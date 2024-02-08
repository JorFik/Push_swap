/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:22:50 by JFikents          #+#    #+#             */
/*   Updated: 2024/02/06 20:10:47 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack_node *stack)
{
	ft_printf("num	index	goal	price\n");
	stack = stack_top(stack);
	while (stack)
	{
		ft_printf("%d	%d	%d	%d\n", stack->num, stack->index, stack->goal,
			stack->price);
		stack = stack->prev;
	}
	ft_printf("\n");
}
