/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:22:50 by JFikents          #+#    #+#             */
/*   Updated: 2024/02/13 16:55:34 by JFikents         ###   ########.fr       */
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

void	print_cmd(int cmd)
{
	if (cmd == SA)
		ft_printf("cmd = sa\n");
	if (cmd == SB)
		ft_printf("cmd = sb\n");
	if (cmd == SS)
		ft_printf("cmd = ss\n");
	if (cmd == PA)
		ft_printf("cmd = pa\n");
	if (cmd == PB)
		ft_printf("cmd = pb\n");
	if (cmd == RA)
		ft_printf("cmd = ra\n");
	if (cmd == RB)
		ft_printf("cmd = rb\n");
	if (cmd == RR)
		ft_printf("cmd = rr\n");
	if (cmd == RRA)
		ft_printf("cmd = rra\n");
	if (cmd == RRB)
		ft_printf("cmd = rrb\n");
	if (cmd == RRR)
		ft_printf("cmd = rrr\n");
}
