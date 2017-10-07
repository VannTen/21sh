/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_defs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 10:46:51 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/07 11:36:29 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAMMAR_DEFS_H
# define GRAMMAR_DEFS_H
# include "grammar_interface.h"
# include "symbol_interface.h"

struct	s_grammar
{
	t_symbol		*symbols;
	t_symbol_type	start_symbol;
};

#endif
