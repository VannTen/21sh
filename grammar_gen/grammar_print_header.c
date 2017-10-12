/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_print_header.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 14:30:48 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/12 14:35:26 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_defs.h"
#include "gram_gen_sym_interface.h"
#include "libft.h"

static void		print_symbol_header(t_symbol const *symbol,
		int const file, const char *prefix, char const *suffix)
{
	char	*name;

	name = ft_strmap(get_name(symbol), f_toupper);
	ft_dprintf(file, "%s%s%s", prefix, name, suffix);
}

static void	adapt_print(void const *symbol, va_list args)
{
	int			fd;
	const char	*prefix_suffix[2];

	fd = va_arg(args, int);
	prefix_suffix[0] = va_arg(args, const char*);
	prefix_suffix[1] = va_arg(args, const char*);
	print_symbol_header(symbol, fd, prefix_suffix[0], prefix_suffix[1]);
}

void		print_grammar_header(t_grammar const *grammar, int const file)
{
	ft_dprintf(file,
			"typedef struct	s_symbol\tt_symbol;\n"
			"typedef enum	e_symbol_type {\n");
	f_fifoiter_va(grammar->sym_list, adapt_print, file,
			"\t", ",\n");
	ft_dprintf(file, "%1$sNB_SYMBOLS\n}%1$st_symbol_type;\n\n", "\t");
}
