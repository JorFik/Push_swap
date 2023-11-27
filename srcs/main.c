/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:23:32 by JFikents          #+#    #+#             */
/*   Updated: 2023/11/27 13:24:35 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int		adj;

	i = 0;
	adj = 1;
	stack->a = NULL;
	stack->b = NULL;
	stack->goal = NULL;
	if (argc == 2)
	{
		adj = 0;
		argv = ft_split(argv[1], ' ');
		argc = count_args(argv);
	}
	stack->goal = (int *)ft_better_calloc(argc - adj, sizeof(int), stack);
	while (argv[i + adj])
	{
		content = ft_better_calloc(1, sizeof(int), stack);
		*content = ft_atoi(argv[i + adj]);
		stack->goal[i++] = *content;
		ft_lstadd_back(&(stack->a), ft_lstnew(content));
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stack;
	int			i;

	i = 0;
	if (argc < 2)
		exit (del_lists(NULL, 1));
	set_the_bases(argv, &stack, argc);
	ft_printf("Init a and b:\n");
	print_nodes(stack.a, stack.b);

	ft_printf("Exec sa:\n");
	swap(stack.a);
	print_nodes(stack.a, stack.b);

	ft_printf("Exec pb pb pb:\n");
	push(&stack.a, &stack.b);
	push(&stack.a, &stack.b);
	push(&stack.a, &stack.b);
	print_nodes(stack.a, stack.b);

	ft_printf("Exec rr:\n");
	rotate_rotate(&stack.a, &stack.b);
	print_nodes(stack.a, stack.b);

	ft_printf("Exec rrr:\n");
	rev_rotate_rotate(&stack);
	print_nodes(stack.a, stack.b);

	ft_printf("Exec sa:	\n");
	swap(stack.a);
	print_nodes(stack.a, stack.b);

	ft_printf("Exec pa pa pa:\n");
	push(&stack.b, &stack.a);
	push(&stack.b, &stack.a);
	push(&stack.b, &stack.a);
	print_nodes(stack.a, stack.b);
	while (i != count_nodes(stack.a) + count_nodes(stack.b))
		ft_printf("%i, ", stack.goal[i++]);
	del_lists(&stack, 0);
	return (0);
}

/*
_sa (swap a):
?	swap(&stack.a);
*	Swap the first 2 elements at the top of stack a.
*	Do nothing if there is only one or no elements.

_sb (swap b):
?	swap(&stack.b);
*	Swap the first 2 elements at the top of stack b.
*	Do nothing if there is only one or no elements.

_ss :
?	swap_swap(&stack.a, &stack.b);
*	sa and sb at the same time.

_pa (push a):
?	push(&stack.b, &stack.a);
*	Take the first element at the top of b and put it at the top of a.
*	Do nothing if b is empty.

_pb (push b):
?	push(&stack.a, &stack.b);
*	Take the first element at the top of a and put it at the top of b.
*	Do nothing if a is empty.

_ra (rotate a):
?	rotate(&stack.a);
*	Shift up all elements of stack a by 1.
*	The first element becomes the last one.

_rb (rotate b):
?	rotate(&stack.b);
*	Shift up all elements of stack b by 1.
*	The first element becomes the last one.

_rr :
?	rotate_rotate(&stack.a, &stack.b);
*	ra and rb at the same time.

_rra (reverse rotate a):
?	rev_rotate(&stack.a);
*	Shift down all elements of stack a by 1.
*	The last element becomes the first one.

_rrb (reverse rotate b):
?	rev_rotate(&stack.b);
*	Shift down all elements of stack b by 1.
*	The last element becomes the first one.

_rrr :
?	rev_rotate_rotate(&stack.a, &stack.b);
*	rra and rrb at the same time.
*/