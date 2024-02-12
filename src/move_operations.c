/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:26:44 by JFikents          #+#    #+#             */
/*   Updated: 2024/02/12 22:19:26 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_move(t_stack_node *stack, int command)
{
	t_moves	*move;

	stack = stack_bottom(stack);
	move = stack->moves;
	if (!move)
	{
		move = ft_calloc(1, sizeof(t_moves));
		exit_on_error((int [3]){IF_NULL, MALLOC_FAIL, N_MOVE}, move, NULL);
		move->cmd = command;
		move->prev = NULL;
		move->next = NULL;
		stack->moves = move;
		return ;
	}
	while (move && move->next)
		move = move->next;
	move->next = ft_calloc(1, sizeof(t_moves));
	exit_on_error((int [3]){IF_NULL, MALLOC_FAIL, N_MOVE}, move->next, NULL);
	move->next->cmd = command;
	move->next->prev = move;
	move->next->next = NULL;
}

static void	r_count(t_moves *moves, int *rs)
{
	rs[RAS] = 0;
	rs[RRAS] = 0;
	rs[RBS] = 0;
	rs[RRBS] = 0;
	while (moves && (moves->cmd == RA || moves->cmd == RB
			|| moves->cmd == RRA || moves->cmd == RRB))
	{
		if (moves->cmd == RA)
			rs[RAS]++;
		else if (moves->cmd == RRA)
			rs[RRAS]++;
		else if (moves->cmd == RB)
			rs[RBS]++;
		else if (moves->cmd == RRB)
			rs[RRBS]++;
		moves = moves->next;
	}
}

static void	jump_moves(t_moves *moves, int cmd)
{
	if (cmd == RR)
	{
		while (moves->cmd != RA)
			moves = moves->next;
		moves->cmd = RR;
		while (moves->cmd != RB)
			moves = moves->next;
		moves->cmd = NONE;
	}
	else if (cmd == RRR)
	{
		while (moves->cmd != RRA)
			moves = moves->next;
		moves->cmd = RRR;
		while (moves->cmd != RRB)
			moves = moves->next;
		moves->cmd = NONE;
	}
}

void	do_moves(t_stack_node *stack)
{
	t_moves	*moves;
	int		rs[4];

	moves = stack->moves;
	while (moves)
	{
		r_count(moves, rs);
		while (rs[RAS] > 0 && rs[RBS] > 0 && rs[RAS]-- && rs[RBS]--)
			jump_moves(moves, RR);
		while (rs[RRAS] > 0 && rs[RRBS] > 0 && rs[RRAS]-- && rs[RRBS]--)
			jump_moves(moves, RRR);
		move(stack, moves->cmd);
		moves = moves->next;
	}
	free_moves(&stack->moves);
}
