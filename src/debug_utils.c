/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:22:50 by JFikents          #+#    #+#             */
/*   Updated: 2024/02/03 13:07:29 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack_node *stack)
{
	ft_printf("num	index	goal\n");
	while (stack)
	{
		ft_printf("%d	%d	%d\n", stack->num, stack->index, stack->goal);
		stack = stack->next;
	}
}
