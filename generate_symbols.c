/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_symbols.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 12:00:03 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/09 14:47:19 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generate_grammar.h"
#include "libft.h"
#include <stdlib.h>

t_symbol	*create_symbol(void)
{
	t_symbol	*new;

	new = malloc(sizeof(t_symbol));
	if (new != NULL)
	{
		new->name = NULL;
		new->productions = NULL;
	}
	return (new);

}

void		destroy_symbol(t_symbol	**to_destroy)
{
	t_symbol	*symbol;

	symbol = *to_destroy;
	if (symbol != NULL)
	{
		ft_strdel(&symbol->name);
		f_lstdel(&symbol->productions, ft_gen_free_string_array);
	}
}

static void	print_prods(char const **prods)
{
	size_t	index;

	index = 0;
	while (prods[index] != NULL)
	{
		ft_printf("%s,", prods[index]);
		index++;
	}
	ft_putchar('\n');
}

static void	print(void *prods)
{
	print_prods(prods);
}

void		print_symbol(t_symbol *to_print)
{
	ft_printf("Name is [%s]\n", to_print->name);
	ft_putendl("Productions are :");
	f_lstiter(to_print->productions, print);
}