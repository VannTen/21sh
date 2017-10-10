/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_source_grammar.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 10:33:24 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/10 12:03:56 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generate_grammar.h"
#include "libft.h"
#include <stdarg.h>
#include <fcntl.h>
#include <unistd.h>

static void	print_prods(const void *v_prod, va_list args)
{
	char const *const	*prod;
	int					fd;

	fd = va_arg(args, int);
	prod = v_prod;
	ft_dprintf(fd, "\t\tnew->productions[index]"
			" = generate_one_production(%zu, ",
			ft_string_array_len(prod));
	ft_print_string_array_fd(fd, prod, ", ");
	ft_putstr_fd(");\n", fd);
	ft_dprintf(fd, "\t\tindex++;\n");

}

static void	print_init_function(t_symbol const *sym, int const fd)
{
	const char	type_name[]	= "t_symbol";
	char		*lower_case;
	size_t		nb_prod;

	if (sym->productions == NULL)
		return ;
	nb_prod = f_lst_len(sym->productions);
	lower_case = ft_strmap(sym->name, f_tolower);
	ft_dprintf(fd, "\n%1$s\t*create_%2$s(void)\n{\n"
			"\t%1$s\t*new;\n"
			"\tsize_t\t\tindex;\n\n"
			"\tnew = malloc(sizeof(t_symbol));\n"
			"\tif (new != NULL)\n\t{\n"
			"\t\tnew->type = %3$s;\n"
			"\t\tindex = 0;\n"
			"\t\tnew->productions = malloc(sizeof(t_symbol_type*)"
			" * (%4$zu + 1));\n"
			, type_name, lower_case, sym->name, nb_prod);
	f_lstiter_va(sym->productions, print_prods, fd);
	ft_dprintf(fd, "\t\tnew->productions[index] = NULL;\n\t}"
			"\n\treturn (new);\n}\n");
}

static void	print_list(const void *v_sym, va_list args)
{
	t_symbol const	*sym;
	int				fd;

	sym = v_sym;
	fd = va_arg(args, int);
	print_init_function(sym, fd);
}

void		print_source(t_lst const *grammar, char const *source_file,
		char const *header_file)
{
	char	*file_no_dir;
	char	*upper_case;
	int		tgt_file;

	(void)header_file;
	tgt_file = open(source_file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	file_no_dir = ft_strdup(get_no_dir_part(source_file));
	upper_case = ft_strmap(file_no_dir, to_unix_const);
	ft_dprintf(tgt_file,
			"#include \"symbol_defs.h\"\n"
			"#include <stdlib.h>\n");
	f_lstiter_va(grammar, print_list, tgt_file);
	close(tgt_file);
}
