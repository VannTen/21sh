/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_grammar_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 13:46:49 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/12 11:37:04 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_defs.h"
#include "libft.h"
#include <stdarg.h>
#include <fcntl.h>
#include <unistd.h>

static void	print_list(void const *v_sym, va_list args)
{
	t_symbol const	*sym;
	char			*name;

	sym = v_sym;
	name = ft_strmap(sym->name, f_tolower);
	ft_dprintf(va_arg(args, int), "create_%s, ", name);
	ft_strdel(&name);
}

void		print_grammar_init(t_grammar const *grammar, char const *init_file)
{
	int		tgt_file;

	tgt_file = open(init_file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	ft_dprintf(tgt_file,
			"#include \"symbol_interface.h\"\n"
			"#include <stdlib.h>\n\n"
			"t_symbol\t**create_grammar(void)\n{\n"
			"\tt_symbol\t**grammar;\n"
			"\tsize_t\t\tindex;\n"
			"\tt_symbol\t*(*init_func[])(void) = {");
	f_lstiter_va(grammar, print_list, tgt_file);
	ft_dprintf(tgt_file, " NULL};\n\n"
			"\tindex = 0;\n"
			"\tgrammar = malloc(sizeof(t_symbol*) * NB_SYMBOLS);\n"
			"\twhile (index < NB_SYMBOLS)\n"
			"\t{\n"
			"\t\tgrammar[index] = init_func[index]();\n"
			"\t\tindex++;\n"
			"\t}\n"
			"\treturn (grammar);\n}\n");
	close(tgt_file);
}
