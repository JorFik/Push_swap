/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:24:00 by JFikents          #+#    #+#             */
/*   Updated: 2023/11/28 17:22:44 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_doubles(t_stacks *stack, int *content)
{
	t_list	*tmp;

	tmp = stack->a;
	while (tmp)
	{
		if (*content == *(int *)(tmp->content))
		{
			ft_free_n_null((void **)&content);
			exit(del_lists(stack, 1));
		}
		tmp = tmp->next;
	}
}

void	check_num(char *argv, t_stacks *stack)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if ((argv[i] == '-' || argv[i] == '+' ) && i == 0)
			i++;
		if (!ft_isdigit(argv[i++]))
			exit(del_lists(stack, 1));
	}
}

void	check_int(char *argv, t_stacks *stack)
{
	if (*argv == '+')
		argv++;
	if (ft_strlen(argv) > 10)
	{
		if (ft_strncmp(argv, "-2147483648", 12) > 0 && argv[0] == '-')
			exit(del_lists(stack, 1));
	}
	else if (ft_strlen(argv) > 9)
	{
		if (ft_strncmp(argv, "2147483647", 11) > 0)
			exit(del_lists(stack, 1));
	}
}
