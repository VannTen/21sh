/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_defs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 10:48:16 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/07 12:18:31 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOL_DEFS_H
# define SYMBOL_DEFS_H
# include "symbol_interface.h"

struct	s_symbol
{
	t_symbol_type	type;
	t_symbol_type	*follow;
	t_symbol_type	*first;
	t_symbol_type	**productions;
};

#endif
