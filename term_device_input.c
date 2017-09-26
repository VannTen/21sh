/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_device_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 14:16:05 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/26 17:45:40 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_device_defs.h"
#include "term_keys_interface.h"
#include "tools_interface.h"
#include "libft.h"
#include <stdarg.h>
#include <stddef.h>

/*
** This function only purpose is to be a relay suitable for f_lstremoveif_va,
** which is why it is declared static (it won't be use anywhere else) and simply
** referencing another function.
*/

static t_bool	match(void const * v_key, va_list args)
{
	const t_key			*key;
	char				c;
	size_t				index;

	key = v_key;
	index = va_arg(args, size_t);
	c = va_arg(args, int);
	return (!could_be_key(key, index, c));
}

t_term_action	find_key_sequence(t_term_device const * term, char *buf,
		size_t	*index)
{
	t_lst	*possible_match;

	possible_match = populate_stack(term->keys_cmd, buf[0]);
	if (possible_match == NULL)
		return (NULL);
	while (f_lst_len(possible_match) > 1)
	{
		if (read_another(term->fd, buf, index))
			f_lstremoveif_va(&possible_match, &match, &no_destroy,
					*index, buf[*index]);
		else
			return (NULL);
	}
	if (f_lst_len(possible_match) == 1)
		return (read_full_key(f_lstpop(&possible_match),
					term->fd, buf, index));
	else
		return (NULL);
}
