/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:23:32 by JFikents          #+#    #+#             */
/*   Updated: 2024/02/07 18:51:24 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	main(int argc, char **argv)
// {
// 	t_stacks	stack;

// 	if (argc < 2)
// 		exit (del_lists(NULL, 0));
// 	set_the_bases(argv, &stack, argc);
// 	ft_printf("Init a and b:\n");
// 	print_nodes(stack.a, stack.b);

// 	ft_printf("Exec ra ra ra:\n");
// 	rotate(&stack.a);
// 	rotate(&stack.a);
// 	rotate(&stack.a);
// 	print_nodes(stack.a, stack.b);

// 	ft_printf("Exec pb pb pb:\n");
// 	push(&stack.a, &stack.b);
// 	push(&stack.a, &stack.b);
// 	push(&stack.a, &stack.b);
// 	print_nodes(stack.a, stack.b);

// 	ft_printf("Exec sa:\n");
// 	rotate(&stack.a);
// 	print_nodes(stack.a, stack.b);

// 	ft_printf("Exec rrb:\n");
// 	rev_rotate(&stack, 'b');
// 	print_nodes(stack.a, stack.b);

// 	ft_printf("Exec pa pa pa:\n");
// 	push(&stack.b, &stack.a);
// 	push(&stack.b, &stack.a);
// 	push(&stack.b, &stack.a);
// 	print_nodes(stack.a, stack.b);
// 	del_lists(&stack, 0);
// 	return (0);
// }

//! STACK A is in ascending order
//! STACK B is in descending order

int	main(int argc, char **argv)
{
	t_stacks	stack;

	if (argc < 2)
		exit (del_lists(NULL, 0));
	set_the_bases(argv, &stack, argc);
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