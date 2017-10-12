/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gram_gen_sym_defs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:33:25 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/11 19:44:08 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAM_GEN_SYM_DEFS_H
# define GRAM_GEN_SYM_DEFS_H
# include "gram_gen_sym_interface.h"
# include "gram_gen_prods_interface.h"
# define DERIVATION_SIGN ':'

struct s_symbol
{
	char	*name;
	t_prod	**prods;
};

#endif
