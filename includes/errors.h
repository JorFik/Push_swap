/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:59:40 by JFikents          #+#    #+#             */
/*   Updated: 2024/02/02 20:15:44 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

// ** ------------------------- MACROS AND ENUMS ------------------------- ** //

enum e_errors
{
	NO_ARG = 1,
	MALLOC_FAIL,
	READ_FAIL,
	FREE_FAIL,
	WRITE_FAIL,
	DUPLICATE,
	NO_INT,
	OUTSIDE_INT,
	IF_NULL = -5102,
	SUCCESS = -5206
};

enum e_where
{
	STACK_A,
	STACK_B,
	ARG,
	READ_ARGS,
	N_NODE
};

enum e_check
{
	STATE,
	ERROR,
	WHERE,
};

//_--------------------------------------------------------------------------_//

#endif /* errors.h */
