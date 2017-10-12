/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_grammar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 10:34:57 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/11 15:45:19 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "generate_grammar.h"

/*
** This small programm has for purpose to generate C files which will initialize
** a grammar (that is, a numerical representation of it) corresponding to the
** parameter given to the programm, such as :
** The first paramater is the grammar file : it shall contained one grammar
** symbol per lines. Symbols names regex : [A-Z_]+.
** Non terminals symbol shall have any number of blank characters (tab and
** spaces following, then a colon, followed by the list of their
** productions.
** Those consists of symbols name separated by spaces or tabs.
** The body of two distincts productions shall be separated by a '|'.
** Finally, every symbols definition (name + productions) shall be followed by
** a semi-colon.
**
** The second paramater shall be a header name, which will hold an enum with all
** the symbols name, and C prototypes for the initialisation functions for each
** symbols.
** The third parameter shall be the C file containing the body of each of these
** functions.
**
** (The fourth paramater might serve in the future for the generated makefile)
*/

char	**split_prod(const char *prod)
{
	char	**splitted_prod;

	splitted_prod = ft_strsplit(prod, ' ');
	return (splitted_prod);
}

t_lst	*get_productions(char const *prods_str)
{
	char	**one_prod;
	char	**productions;
	t_lst	*prods;
	size_t	index;

	productions = ft_strsplit(prods_str, '|');
	index = 0;
	prods = NULL;
	while (productions[index] != NULL)
	{
		one_prod = split_prod(productions[index]);
		f_lstpush(one_prod, &prods);
		one_prod = NULL;
		index++;
	}
	ft_free_string_array(&productions);
	return (prods);
}

t_symbol	*parse_symbol(char **src)
{
	char		*name;
	char		*productions;
	t_symbol	*new_symbol;

	name = ft_strip(src[0]," \t\n");
	if (name == NULL)
		return (NULL);
	new_symbol = create_symbol();
	new_symbol->name = (char*)name;
	if (src[1] != NULL)
	{
		productions = ft_strip(src[1], "\n\t");
		new_symbol->productions = get_productions(productions);
		ft_strdel(&productions);
	}
	else
		new_symbol->productions = NULL;
	return (new_symbol);
}

void	print_files(t_lst const *sym_list, char const *gram_name)
{
	char	*stem;
	char	*header;
	char	*src;
	char	*init;
	char	*names;

	stem = ft_strndup(gram_name, ft_strlen_gen(gram_name, '.'));
	header = ft_strvajoin(3, "includes/", stem, "_interface.h");
	src = ft_strjoin(stem, "_source.c");
	init = ft_strjoin(stem, "_init.c");
	names = ft_strjoin(stem, "_names.c");
	print_header(sym_list, header);
	print_source(sym_list, src);
	print_init(sym_list, init);
	print_names(sym_list, names);
	ft_strdel(&stem);
	ft_strdel(&header);
	ft_strdel(&src);
	ft_strdel(&init);
	ft_strdel(&names);
}

int	main(int argc, const char **argv)
{
	int			grammar;
	char		*line;
	t_symbol	*symbol;
	t_lst		*sym_list;
	char		**sym;

	if (argc != 2)
		return (EXIT_FAILURE);
	grammar = open(argv[1], O_RDONLY);
	sym_list = NULL;
	while (get_next_elem(grammar, &line, ';') == ONE_LINE_READ
			&& line[0] != '\0')
	{
		symbol = parse_symbol(sym);
		if (symbol != NULL)
			f_lstpush(symbol, &sym_list);
		ft_strdel(&line);
		ft_free_string_array(&sym);
	}
	close(grammar);
	print_files(sym_list, argv[1]);
	f_lstdel(&sym_list, destroy_symbol);
	return (0);
}
