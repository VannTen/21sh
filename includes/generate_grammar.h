/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_grammar.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 11:57:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/09 18:30:41 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERATE_GRAMMAR_H
# define GENERATE_GRAMMAR_H
# include "libft.h"

typedef struct	s_symbol
{
	char	*name;
	t_lst	*productions;
}				t_symbol;

t_symbol	*create_symbol(void);
void		destroy_symbol(t_symbol **to_destroy);
void		print_symbol(t_symbol *to_print);

/*
** Print the grammar
*/

void	print_header(t_lst const *grammar, const char *header_file);
void	print_source(t_lst const *grammar, char const *source_file,
		const char *header_file);
#endif
