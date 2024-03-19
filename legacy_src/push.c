/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:28:20 by JFikents          #+#    #+#             */
/*   Updated: 2023/11/24 10:57:54 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **from, t_list **to)
{
	if (!*from)
		return ;
	ft_lstadd_front(to, ft_lstnew((*from)->content));
	del_front_n_relink(from);
}
