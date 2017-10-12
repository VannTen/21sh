/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gramm_gen_sym_parse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 14:26:14 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/12 11:07:26 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gram_gen_sym_defs.h"

t_symbol	*parse_symbol(char const *src)
{
	char		**name_and_prods;
	char		*name;
	t_symbol	*new_symbol;

	name_and_prods = ft_strsplit(src, DERIVATION_SIGN);
	name = ft_strip(name_and_prods[0], " \t\n");
	if (name_and_prods == NULL)
		return (NULL);
	new_symbol = create_symbol(name);
	if (name_and_prods[1] != NULL)
		new_symbol->prods = parse_prods(name_and_prods[1]);
	else
		new_symbol->prods = NULL;
	ft_free_string_array(&name_and_prods);
	return (new_symbol);
}
