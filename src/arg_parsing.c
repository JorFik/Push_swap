/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:54:38 by JFikents          #+#    #+#             */
/*   Updated: 2024/02/03 13:52:11 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_duplicate(t_stack_node stack[2], int num)
{
	t_stack_node	*tmp;

	tmp = &stack[A];
	while (tmp)
	{
		if (tmp->num == num)
			exit_on_error((int [3]){-1, DUPLICATE, ARG}, NULL, stack);
		tmp = tmp->next;
	}
}

static void	check_num(char *argv, t_stack_node stack[2])
{
	int	i;

	i = 0;
	if (argv[i] == '-' || argv[i] == '+' )
		i++;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i++]))
			exit_on_error((int [3]){-1, NO_INT, ARG}, NULL, stack);
	}
}

static void	check_int(char *argv, t_stack_node stack[2])
{
	int	lenght;
	int	sign;
	int	i;

	sign = 1;
	i = 1;
	if (*argv == '+')
		argv++;
	while (*argv == '0')
		argv++;
	lenght = ft_strlen(argv);
	if ((lenght < 10)
		|| (lenght == 11 && ft_strncmp(argv, "-2147483648", 12) <= 0)
		|| (lenght == 10 && ft_strncmp(argv, "2147483647", 11) <= 0))
		return ;
	exit_on_error((int [3]){-1, OUTSIDE_INT, ARG}, NULL, stack);
}

void	check_arg(char *argv, t_stack_node stack[2])
{
	t_stack_node	*last;

	check_num(argv, stack);
	check_int(argv, stack);
	last = stack_last(&stack[A]);
	if (last->index != START_INDEX - 1)
		check_duplicate(stack, ft_atoi(argv));
}
