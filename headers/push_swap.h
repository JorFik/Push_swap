/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:15:17 by JFikents          #+#    #+#             */
/*   Updated: 2023/11/30 18:20:39 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdlib.h> // malloc free
# include <limits.h> // INT_MAX INT_MIN

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
}	t_stacks;

//_Checks
void	check_doubles(t_stacks *stack, int *content);
void	check_num(char *argv, t_stacks *stack);
void	check_int(char *argv, t_stacks *stack);

//_ Basic Moves
void	swap_swap(t_list *stack_a, t_list *stack_b);
void	swap(t_list *stack);
void	push(t_list **from, t_list **to);
void	rotate_rotate(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack);
void	rev_rotate_rotate(t_stacks *stack);
void	rev_rotate(t_stacks *stack, char a_b);

//_ Utils
void	print_nodes(t_list *stack_a, t_list *stack_b);
int		count_nodes(t_list *stack);
void	*ft_better_calloc(size_t count, size_t size, t_stacks *stack);
void	set_the_bases(char **argv, t_stacks *stack, int argc);

//_Del Utils
void	ft_free_n_null(void **ptr);
int		del_lists(t_stacks *stack, int error_message);
void	del_front_n_relink(t_list **stack);
void	del_end_n_relink(t_list *stack);

#endif