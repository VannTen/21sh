/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_grammar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:12:55 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/09 19:14:07 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generate_grammar.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

static char	to_unix_const(char c)
{
	if (c == '.')
		return ('_');
	else
		return (ft_toupper(c));
}

static void		print_name(const void *v_symbol, va_list arg)
{
	t_symbol const	*symbol;
	int				fd;

	symbol = v_symbol;
	fd = va_arg(arg, int);
	ft_dprintf(fd, "%4s%s,\n", "", symbol->name);
}

void		print_prods(const void *v_prod, va_list args)
{
	char const	*const*prod;
	int			fd;

	fd = va_arg(args, int);
	prod = v_prod;
	ft_dprintf(fd, "new->productions[index] = {");
	ft_print_string_array_fd(fd, (char const *const*)prod, ',');
	ft_putstr_fd("};\n", fd);
	ft_dprintf(fd, "index++;\n");

}

void		print_prot_init_function(t_symbol const *sym, int const fd)
{
	char	type_name[]	= "t_symbol";
	char	*lower_case;
	size_t	nb_prod;

	if (sym->productions == NULL)
		return ;
	nb_prod = f_lst_len(sym->productions);
	lower_case = ft_strmap(sym->name, f_tolower);
	ft_dprintf(fd, "%2$s %1$3s *create_%3$s(void);\n"
			, "", type_name, lower_case);
}
void		print_init_function(t_symbol const *sym, int const fd)
{
	char	type_name[]	= "t_symbol";
	char	*lower_case;
	size_t	nb_prod;

	if (sym->productions == NULL)
		return ;
	nb_prod = f_lst_len(sym->productions);
	lower_case = ft_strmap(sym->name, f_tolower);
	ft_dprintf(fd, "\n%2$s %1$3s *create_%3$s(void)\n{\n"
			"%2$-4s *new;\n"
			"size_t	nb_prod;\n"
			"size_t	index;\n\n"
			"if (new != NULL)\n"
			"new->type = %4$s;\n"
			"index = 0;\n"
			"new->productions = malloc(sizeof(t_symbol_type*) * %5$zu);\n"
			, "", type_name, lower_case, sym->name, nb_prod);
	f_lstiter_va(sym->productions, print_prods, fd);
	ft_dprintf(fd, "return (new);\n}\n");
}

static void	print_list(const void *v_sym, va_list args)
{
	t_symbol const	*sym;
	int				fd;

	sym = v_sym;
	fd = va_arg(args, int);
	print_init_function(sym, fd);
}

static void	print_list_2(const void *v_sym, va_list args)
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
	ft_dprintf(tgt_file, "#ifndef %1$s\n# define %1$s\n"
			"# include \"symbol_defs.h\"\n"
			"typedef enum	e_symbol_type {\n",
			upper_case);
	f_lstiter_va(grammar, print_name, tgt_file);
	ft_dprintf(tgt_file, "%1$4sNB_SYMBOLS\n}%1$4st_symbol_type;\n\n", "");
	f_lstiter_va(grammar, print_list_2, tgt_file);
	ft_dprintf(tgt_file, "\n#endif\n");
	close(tgt_file);
}

void		print_source(t_lst const *grammar, char const *source_file,
		char const *header_file)
{
	char	*file_no_dir;
	char	*upper_case;
	int		tgt_file;

	tgt_file = open(source_file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	file_no_dir = ft_strdup(get_no_dir_part(source_file));
	upper_case = ft_strmap(file_no_dir, to_unix_const);
	ft_dprintf(tgt_file, "#include \"%s\"\n"
			"#include \"symbol_defs.h\"\n"
			"#include <stdlib.h>\n\n",
			get_no_dir_part(header_file));
	f_lstiter_va(grammar, print_list, tgt_file);
}
