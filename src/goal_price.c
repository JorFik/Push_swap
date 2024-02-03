/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goal_price.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:01:27 by JFikents          #+#    #+#             */
/*   Updated: 2024/02/03 14:11:59 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_goal(t_stack_node *stack)
{
	t_stack_node	*next_low;
	static int		index = START_INDEX;

	next_low = stack;
	while (stack)
	{
		if ((stack->num < next_low->num && stack->goal == START_INDEX - 1)
			|| next_low->goal != START_INDEX - 1)
			next_low = stack;
		stack = stack->next;
	}
	if (next_low->goal == START_INDEX - 1)
	{
		next_low->goal = index++;
		set_goal(stack_first(next_low));
	}
}
