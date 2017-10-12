/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_grammar_names.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 16:26:49 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/10 16:34:31 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generate_grammar.h"
#include "libft.h"
#include <stdarg.h>
#include <fcntl.h>
#include <unistd.h>

static void		print_list(void const *v_sym, va_list args)
{
	t_symbol const	*sym;

	sym = v_sym;
	ft_dprintf(va_arg(args, int), "\"%s\", ", sym->name);
}

void		print_names(t_lst const *grammar, char const *names_file)
{
	int		tgt_file;

	tgt_file = open(names_file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	ft_dprintf(tgt_file,
			"#include \"symbol_interface.h\"\n"
			"#include <stdlib.h>\n\n"
			"char const\t*get_symbol_name(t_symbol_type const index){\n"
			"\tstatic char const *names[] = {");
	f_lstiter_va(grammar, print_list, tgt_file);
	ft_dprintf(tgt_file, " NULL};\n\n"
			"\treturn (names[index]);\n}\n");
	close(tgt_file);
}
