/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 18:05:32 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/26 17:59:09 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_keys_defs.h"
#include "tools_interface.h"
#include "libft.h"

t_lst			*populate_stack(t_key *keys, char c)
{
	size_t	index;
	t_lst	*stack;

	index = 0;
	stack = NULL;
	while (keys[index].str != NULL)
	{
		if (keys[index].str[0] == c)
			f_lstpush(keys + index, &stack);
		index++;
	}
	return (stack);
}

t_term_action	read_full_key(t_key const *key,
		int fd, char *buf, size_t *index)
{
	while (key->str[*index + 1] != '\0'
			&& read_another(fd, buf, index)
			&& could_be_key(key, *index, buf[*index]))
	{
	}
	if (ft_strequ(key->str, buf))
	{
		*index = 0;
		return (key->action);
	}
	else
		return (NULL);
}

t_bool			could_be_key(t_key const *key, size_t index, int c)
{
	return (key->str[index] == c);
}

t_term_action	get_key_action(t_key const *key)
{
	return (key->action);
}
