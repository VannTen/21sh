/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_grammar.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 11:57:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/09 14:45:50 by mgautier         ###   ########.fr       */
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
#endif
