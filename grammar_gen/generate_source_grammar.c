/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_source_grammar.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 10:33:24 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/11 20:13:42 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generate_grammar.h"
#include "libft.h"
#include <stdarg.h>
#include <fcntl.h>
#include <unistd.h>

/*
static void	print_prods(const void *v_prod, va_list args)
{
	char const *const	*prod;
	int					fd;

	fd = va_arg(args, int);
	prod = v_prod;

}

static void	print_init_function(t_symbol const *sym, int const fd)
{
}
*/

static void	print_list(const void *v_sym, va_list args)
{
	t_symbol const	*sym;
	int				fd;

	sym = v_sym;
	fd = va_arg(args, int);
//	print_init_function(sym, fd);
}

void		print_source(t_lst const *grammar, char const *source_file)
{
	char	*file_no_dir;
	char	*upper_case;
	int		tgt_file;

	tgt_file = open(source_file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	file_no_dir = ft_strdup(get_no_dir_part(source_file));
	upper_case = ft_strmap(file_no_dir, to_unix_const);
	ft_dprintf(tgt_file,
			"#include \"symbol_defs.h\"\n"
			"#include <stdlib.h>\n");
	f_lstiter_va(grammar, print_list, tgt_file);
	close(tgt_file);
}
