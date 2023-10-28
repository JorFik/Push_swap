/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:33:48 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/29 01:06:01 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_2nd_flags(const char *formato, va_list input)
{
	va_list	c_input;

	va_copy(c_input, input);
	if (*formato == '0' && ft_isdigit(formato[1]))
		;
	if (*formato == '-' && ft_isdigit(formato[1]))
		;
	if (*formato == '.' && ft_isdigit(formato[1]))
		;
	va_end(c_input);
	return (0);
}

int	ft_bonus_flags(const char *formato, va_list input)
{
	va_list	c_input;

	if ((*formato == ' ' || *formato == '+')
		&& (formato[1] == 'd' || formato[1] == 'i'))
	{
		va_copy(c_input, input);
		if (va_arg(c_input, int) >= 0)
		{
			if (*formato == '+')
				return (ft_putchar('+'));
			if (*formato == ' ')
				return (ft_putchar(' '));
		}
		va_end(c_input);
	}
	if (*formato == ' ' && formato[1] == 's')
		return (ft_putchar(' '));
	if (*formato == '#' && formato[1] == 'x')
		return (ft_putstr("0x"));
	if (*formato == '#' && formato[1] == 'X')
		return (ft_putstr("0X"));
	return (ft_2nd_flags(formato, input));
}

//_ '0': Rellena ceros inicio si el ancho del campo > número.
//_ '.': Controla el número de decimales y el máximo de char in str.
//_ ' ': if(número >= 0, inicio ' '; else '-'.
//_ '+': if(número >= 0, inicio '+'; else '-'.
//_ '-': el relleno va al final.

// * s (Cadena de caracteres):
// ?    ancho mínimo y '.'

// * p (Puntero):
//  ?   ancho mínimo y la precisión para controlar la impresión del puntero.

// * d, i (Enteros con signo):
//   ?  ancho mínimo y '.', '0' para rellenar con ceros.

// * u, x, X (U INT, hex y hex_up):
//   ?  ancho mínimo y '.', '0' para rellenar con ceros.