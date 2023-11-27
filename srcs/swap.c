/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:28:30 by JFikents          #+#    #+#             */
/*   Updated: 2023/11/21 12:47:48 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack)
{
	if (!stack || !stack->next)
		return ;
	*((int *)stack->content) ^= *((int *)stack->next->content);
	*((int *)stack->next->content) ^= *((int *)stack->content);
	*((int *)stack->content) ^= *((int *)stack->next->content);
}

void	swap_swap(t_list *stack_a, t_list *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
