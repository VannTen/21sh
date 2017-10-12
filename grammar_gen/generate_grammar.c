/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_grammar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 10:34:57 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/12 12:34:20 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_interface.h"
#include "libft.h"

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
	t_grammar	*grammar;
	char		*stem;

	if (argc != 2)
		return (EXIT_FAILURE);
	grammar = parse_grammar(argv[1]);
	if (grammar != NULL)
	{
		print_grammar(stem);
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
