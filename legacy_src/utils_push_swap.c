/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:33:16 by JFikents          #+#    #+#             */
/*   Updated: 2023/11/28 19:29:48 by JFikents         ###   ########.fr       */
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

int	count_args(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void	set_the_bases(char *argv[], t_stacks *stack, int argc)
{
	int		*content;
	int		i;

	i = 1;
	stack->a = NULL;
	stack->b = NULL;
	if (argc == 2)
	{
		i = 0;
		argv = ft_split(argv[1], ' ');
		argc = count_args(argv);
	}
	while (argv[i])
	{
		check_num(argv[i], stack);
		check_int(argv[i], stack);
		content = ft_better_calloc(1, sizeof(int), stack);
		*content = ft_atoi(argv[i++]);
		check_doubles(stack, content);
		ft_lstadd_back(&(stack->a), ft_lstnew(content));
	}
}
