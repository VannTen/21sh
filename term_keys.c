/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 18:05:32 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/26 12:21:19 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_keys_defs.h"
#include "libft.h"
#include <unistd.h>

t_lst	*populate_stack(t_key *keys, char c)
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
	size_t	seq_size;
	int		ret;

	seq_size = ft_strlen(key->str);
	while (*index < seq_size && ft_strequ_short(key->str, buf))
	{
		ret = read(fd, buf + *index, 1);
		(*index)++;
		buf[*index] = '\0';
		if (ret == -1)
			fatal();
		else if (ret == 0)
			return (NULL);
	}
	if (ft_strequ(key->str, buf))
	{
		*index = 0;
		return (key->action);
	}
	else
	{
		(*index)--;
		return (NULL);
	}
}

t_bool	could_be_key(t_key const *key, size_t index, int c)
{
	return (key->str[index] == c);
}

t_term_action	get_key_action(t_key const * key)
{
	return (key->action);
}
