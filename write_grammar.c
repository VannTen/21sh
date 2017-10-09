/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_grammar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:12:55 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/09 16:24:24 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generate_grammar.h"
#include "libft.h"
#include <fcntl.h>

static char	to_unix_const(char c)
{
	if (c == '.')
		return ('_');
	else
		return (ft_toupper(c));
}

static void		print_name(void *v_symbol)
{
	t_symbol	*symbol;

	symbol = v_symbol;
	ft_printf("%4s%s,\n", "", symbol->name);
}
void			print_list_symbols(t_lst const *list_symbols)
{
	f_lstiter((t_lst*)list_symbols, print_name);
}

void		print_header(t_lst const *grammar, const char *header_file)
{
	char	*file_no_dir;
	char	*upper_case;

	//tgt_file = open(header_file, O_CREAT | O_TRUNC | O_WRONLY);
	file_no_dir = ft_strdup(get_no_dir_part(header_file));
	upper_case = ft_strmap(file_no_dir, to_unix_const);
	ft_printf("#ifndef %1$s\n# define %1$s\n\n", upper_case);
	ft_printf("typedef enum	e_symbol_type {\n");
	print_list_symbols(grammar);
	ft_printf("%1$4sNB_SYMBOLS\n}%1$4st_symbol_type;\n", "");
	ft_printf("\n#endif\n");
}
