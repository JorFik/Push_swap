/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:33:06 by JFikents          #+#    #+#             */
/*   Updated: 2024/02/06 13:40:35 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_param(t_stack_node stack[2], int goal_or_num)
{
	if (goal_or_num == NUM)
	{
		stack->num ^= stack->prev->num;
		stack->prev->num ^= stack->num;
		stack->num ^= stack->prev->num;
	}
	if (goal_or_num == GOAL)
	{
		stack->goal ^= stack->prev->goal;
		stack->prev->goal ^= stack->goal;
		stack->goal ^= stack->prev->goal;
	}
	if (goal_or_num == REV_NUM)
	{
		stack->num ^= stack->next->num;
		stack->next->num ^= stack->num;
		stack->num ^= stack->next->num;
	}
}

static void	swap(t_stack_node stack[2], int cmd)
{
	if ((cmd == SA || cmd == SS) && stack[A].prev)
	{
		swap_param(stack, NUM);
		swap_param(stack, GOAL);
	}
	stack = stack_top(&(stack_bottom(stack))[B]);
	if ((cmd == SB || cmd == SS) && stack->prev)
	{
		swap_param(stack, NUM);
		swap_param(stack, GOAL);
	}
	if (cmd == SS)
		ft_printf("ss\n");
	if (cmd == SA)
		ft_printf("sa\n");
	if (cmd == SB)
		ft_printf("sb\n");
}

static void	reverse_rotate(t_stack_node stack[2], int cmd)
{
	if ((cmd == RRA || cmd == RRR))
		stack = stack_top(stack);
	while (stack->prev && (cmd == RRA || cmd == RRR))
	{
		swap_param(stack, NUM);
		stack = stack->prev;
	}
	stack = stack_top(&stack[B]);
	while (stack->prev && (cmd == RRB || cmd == RRR))
	{
		swap_param(stack, NUM);
		stack = stack->prev;
	}
	if (cmd == RRR)
		ft_printf("rrr\n");
	if (cmd == RRA)
		ft_printf("rra\n");
	if (cmd == RRB)
		ft_printf("rrb\n");
}

static void	rotate(t_stack_node stack[2], int cmd)
{
	stack = stack_bottom(stack);
	while (stack->next && (cmd == RA || cmd == RR))
	{
		swap_param(stack, REV_NUM);
		stack = stack->next;
	}
	stack = &(stack_bottom(stack))[B];
	while (stack->next && (cmd == RB || cmd == RR))
	{
		swap_param(stack, REV_NUM);
		stack = stack->next;
	}
	if (cmd == RR)
		ft_printf("rr\n");
	if (cmd == RA)
		ft_printf("ra\n");
	if (cmd == RB)
		ft_printf("rb\n");
}

void	move(t_stack_node stack[2], int cmd)
{
	if (cmd >= SA && cmd <= SS)
		swap(stack_top(stack), cmd);
	if (cmd == PA)
	{
		push_a(stack);
		ft_printf("pa\n");
	}
	if (cmd == PB)
	{
		push_b(stack);
		ft_printf("pb\n");
	}
	if (cmd >= RA && cmd <= RR)
		rotate(stack, cmd);
	if (cmd >= RRA && cmd <= RRR)
		reverse_rotate(stack, cmd);
}
