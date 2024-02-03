/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goal_price.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:01:27 by JFikents          #+#    #+#             */
/*   Updated: 2024/02/03 12:17:55 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_goal(t_stack_node *stack)
{
	int		lowest;

	lowest = stack->num;
	while (stack->next)
	{
		if (stack->next->num < lowest)
			lowest = stack->next->num;
		stack = stack->next;
	}
	print_stack(stack_first(stack));
	ft_printf("lowest: %d\n", lowest);
}
