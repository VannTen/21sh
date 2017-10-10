/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_interface.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 10:49:41 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/10 12:05:18 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOL_INTERFACE_H
# define SYMBOL_INTERFACE_H
# include "gen_grammar_interface.h"
# include <stddef.h>

t_symbol_type	*generate_one_production(size_t nb, ...);

# define SYMBOL_END NB_SYMBOLS

#endif
