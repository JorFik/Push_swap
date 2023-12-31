/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_utils_push_swap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:46:13 by JFikents          #+#    #+#             */
/*   Updated: 2023/11/26 20:04:48 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	del_lists(t_stacks *stack, int error_message)
{
	t_list	*tmp;

	while (stack && stack->a)
	{
		tmp = (stack->a)->next;
		if (stack->a)
			ft_free_n_null((&(stack->a)->content));
		if (stack->a)
			ft_free_n_null((void **)stack->a);
		stack->a = tmp;
	}
	while (stack && stack->b)
	{
		tmp = (stack->b)->next;
		ft_free_n_null((void *)(stack->b)->content);
		ft_free_n_null((void **)stack->b);
		stack->b = tmp;
	}
	if (stack && stack->goal)
		ft_free_n_null((void **)&stack->goal);
	if (error_message)
		ft_printf("Error\n");
	return (1);
}

void	ft_free_n_null(void **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}

void	del_end_n_relink(t_list *stack)
{
	t_list	*tmp;
	int		i;

	if ((stack)->next == NULL)
	{
		(stack)->content = NULL;
		return ;
	}
	i = count_nodes(stack);
	while (i-- > 2)
		stack = stack->next;
	tmp = stack->next;
	stack->next = NULL;
	ft_free_n_null((void **)&tmp);
}

void	del_front_n_relink(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	ft_free_n_null((void **)&tmp);
}
