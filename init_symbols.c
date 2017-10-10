/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_symbols.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 10:56:32 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/10 10:59:34 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "symbol_interface.h"
#include <stdlib.h>
#include <stdarg.h>

t_symbol_type	generate_one_production(size_t nb, ...)
{
	t_symbol_type	production;
	size_t			index;
	va_list			list_symbol;

	production = malloc(sizeof(t_symbol_type) * nb + 1);
	index = 0;
	if (production != NULL)
	{
		va_start(nb, list_symbol);
		while (index < nb)
		{
			production[index] = va_arg(list_symbol, t_symbol_type);
			index++;
		}
		va_end(list_symbol);
		production[index] = NB_SYMBOLS;
	}
	return (production);
}
