/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_header_grammar.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 10:37:37 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/10 15:56:48 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generate_grammar.h"
#include "libft.h"
#include <stdarg.h>
#include <fcntl.h>
#include <unistd.h>

char		to_unix_const(char c)
{
	if (c == '.')
		return ('_');
	else
		return (ft_toupper(c));
}

static void	print_name(const void *v_symbol, va_list arg)
{
	t_symbol const	*symbol;
	int				fd;

	symbol = v_symbol;
	fd = va_arg(arg, int);
	ft_dprintf(fd, "%4s%s,\n", "", symbol->name);
}

static void	print_prot_init_function(t_symbol const *sym, int const fd)
{
	char	type_name[]	= "t_symbol";
	char	*lower_case;
	size_t	nb_prod;

	nb_prod = f_lst_len(sym->productions);
	lower_case = ft_strmap(sym->name, f_tolower);
	ft_dprintf(fd, "%s\t*create_%s(void);\n"
			, type_name, lower_case);
}

static void	print_list(const void *v_sym, va_list args)
{
	t_symbol const	*sym;
	int				fd;

	sym = v_sym;
	fd = va_arg(args, int);
	print_prot_init_function(sym, fd);
}

void		print_header(t_lst const *grammar, const char *header_file)
{
	char	*file_no_dir;
	char	*upper_case;
	int		tgt_file;

	tgt_file = open(header_file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	file_no_dir = ft_strdup(get_no_dir_part(header_file));
	upper_case = ft_strmap(file_no_dir, to_unix_const);
	ft_dprintf(tgt_file, "#ifndef %1$s\n# define %1$s\n\n"
			"typedef struct	s_symbol\tt_symbol;\n"
			"typedef enum	e_symbol_type {\n",
			upper_case);
	f_lstiter_va(grammar, print_name, tgt_file);
	ft_dprintf(tgt_file, "%1$4sNB_SYMBOLS\n}%1$4st_symbol_type;\n\n", "");
	f_lstiter_va(grammar, print_list, tgt_file);
	ft_dprintf(tgt_file, "t_symbol\t**create_grammar(void);\n");
	ft_dprintf(tgt_file, "\n#endif\n");
	close(tgt_file);
}
