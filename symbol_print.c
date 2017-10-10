/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 15:58:14 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/10 17:12:29 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "symbol_defs.h"
#include "libft.h"

static void	print_prod(t_symbol_type *prod)
{
	size_t	index;

	index = 0;
	while (prod[index] != NB_SYMBOLS)
	{
		ft_printf("%s ", get_symbol_name(prod[index]));
		index++;
	}
}

void		print_symbol(t_symbol const *sym)
{
	size_t	index;

	ft_printf("%s :\n", get_symbol_name(sym->type));
	if (sym->productions == NULL)
		ft_printf("is a terminal\n");
	else
	{
		index = 0;
		while (sym->productions[index] != NULL)
		{
			print_prod(sym->productions[index]);
			index++;
			ft_putchar('\n');
			if (sym->productions[index] != NULL)
				ft_putchar('|');
		}
	}
}
