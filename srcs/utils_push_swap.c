/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:33:16 by JFikents          #+#    #+#             */
/*   Updated: 2023/11/26 20:05:21 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_nodes(t_list *stack_a, t_list *stack_b)
{
	int	size_a;
	int	size_b;

	size_a = count_nodes(stack_a);
	size_b = count_nodes(stack_b);
	while (size_a && size_a != size_b && (size_a-- > size_b))
	{
		ft_printf("	%i\n", *(int *)(stack_a->content));
		stack_a = stack_a->next;
	}
	while (size_b && size_a != size_b && size_b-- > size_a)
	{
		ft_printf("		%i\n", *(int *)(stack_b->content));
		stack_b = stack_b->next;
	}
	while (stack_a && stack_b)
	{
		ft_printf("	%i	%i\n", *(int *)(stack_a->content),
			*(int *)(stack_b->content));
		stack_a = stack_a->next;
		stack_b = stack_b->next;
	}
	ft_printf("	-	-\n");
	ft_printf("	A	B\n");
	ft_printf("------------------------------------------------------------\n");
}

int	count_nodes(t_list *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	*ft_better_calloc(size_t count, size_t size, t_stacks *stack)
{
	void			*new_p;
	unsigned long	i;

	i = 0;
	new_p = malloc(count * size);
	if (!new_p)
		exit (del_lists(stack, 1));
	while ((count * size) > i)
	{
		((char *)new_p)[i] = 0;
		i ++;
	}
	return (new_p);
}
