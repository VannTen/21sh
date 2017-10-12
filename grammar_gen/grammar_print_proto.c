/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_print_proto.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 14:20:45 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/12 16:30:37 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_defs.h"
#include "gram_gen_sym_interface.h"
#include "libft.h"

static void		print_symbol_proto(t_symbol const *symbol,
		int const file, const char *prefix, char const *suffix)
{
	char	*name;

	name = ft_strmap(get_name(symbol), f_tolower);
	ft_dprintf(file, "%s%s%s", prefix, name, suffix);
}

static void	adapt_print(void const *symbol, va_list args)
{
	int			fd;
	const char	*prefix_suffix[2];

	fd = va_arg(args, int);
	prefix_suffix[0] = va_arg(args, const char*);
	prefix_suffix[1] = va_arg(args, const char*);
	print_symbol_proto(symbol, fd, prefix_suffix[0], prefix_suffix[1]);
}

void		print_grammar_proto(t_grammar const *grammar, int const file)
{
	f_fifoiter_va(grammar->sym_list, adapt_print, file,
			"t_symbol\t*create_", ";\n");
}
