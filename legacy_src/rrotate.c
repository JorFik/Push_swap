/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:28:26 by JFikents          #+#    #+#             */
/*   Updated: 2023/11/26 20:01:26 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stacks *stack, char a_b)
{
	int	*new_old_content;

	if (!stack || (a_b == 'a' && (!stack->a || !(stack->a)->next))
		|| (a_b == 'b' && (!stack->b || !(stack->b)->next)))
		return ;
	new_old_content = ft_better_calloc(1, sizeof(int), stack);
	if (a_b == 'a')
	{
		new_old_content = (int *)ft_memcpy(new_old_content,
				(ft_lstlast(stack->a))->content, sizeof(int));
		ft_lstadd_front(&stack->a, ft_lstnew(new_old_content));
		del_end_n_relink(stack->a);
	}
	if (a_b == 'b')
	{
		new_old_content = (int *)ft_memcpy(new_old_content,
				(ft_lstlast(stack->b))->content, sizeof(int));
		ft_lstadd_front(&stack->b, ft_lstnew(new_old_content));
		del_end_n_relink(stack->b);
	}
}

void	rev_rotate_rotate(t_stacks *stack)
{
	rev_rotate(stack, 'a');
	rev_rotate(stack, 'b');
}
