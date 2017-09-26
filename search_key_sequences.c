/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_key_sequences.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 10:47:09 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/26 13:16:07 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_device_defs.h"
#include "term_actions_defs.h"
#include "interactive_string_interface.h"
#include "term_keys_interface.h"
#include "libft.h"
#include <stdarg.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

# define MAX_SEQ_LENGHT 10

/*
** Keep those
*/

t_term_action	consume_one_sequence(t_key const *key, char *buf, size_t *index,
		t_line_editor *buffer)
{
	t_term_action	key_action;

	key_action = read_full_key(key, get_fd(buffer->term), buf, index);
	return (key_action);
}

static size_t	send_to_buffer(char *buf, t_line_editor *term, size_t nb_char)
{
	size_t	index;
	void	*ret;

	index = 0;
	ret = &index;
	while (index < nb_char && ret != NULL)
	{
		ret = add_letter(term->buffer, buf[index]);
		insert_character(term->term, buf[index]);
		buf[index] = '\0';
		index++;
	}
	if (buf[index] != '\0')
		buf[0] = buf[index];
	return (ret != NULL ? index : index - 1);
}

/*
** Term device side
*/

/*
** This function only purpose is to be a relay suitable for f_lstremoveif_va,
** which is why it is declared static (it won't be use anywhere else) and simply
** referencing another function (though that one is not used for anything else
** at the time this comment is written
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

t_term_action	search_seq(char *buf, t_line_editor *buffer, size_t	*index)
{
	t_lst	*possible_match;
	int		ret;

	possible_match = populate_stack(buffer->term->keys_cmd, buf[0]);
	if (possible_match == NULL)
		return (NULL);
	while (f_lst_len(possible_match) > 1)
	{
		ret = read(buffer->term->fd, buf + *index, 1);
		(*index)++;
		buf[*index] = '\0';
		if (ret == 0)
			return (NULL);
		else
			f_lstremoveif_va(&possible_match, &match, &no_destroy,
					*index - 1, buf[*index - 1]);
	}
	if (f_lst_len(possible_match) == 1)
		return (consume_one_sequence(f_lstpop(&possible_match), buf, index,
					buffer));
	else
		return (NULL);
}

t_bool		is_validated(t_line_editor *buf)
{
	return (get_current_letter(buf->buffer) == '\n' ||
			int_str_get_size(buf->buffer) > 20);
}

int	search_for_sequence(t_line_editor *term)
{
	char			buf[10];
	size_t			index;
	t_term_action	key_to_do;

	buf[0] = '\0';
	while (!is_validated(term))
	{
		if (buf[0] == '\0')
			read(term->term->fd, &buf, 1);
		index = 1;
		buf[1] = '\0';
		key_to_do = search_seq(buf, term, &index);
		if (key_to_do == NULL)
			send_to_buffer(buf, term, index);
		else
		{
			key_to_do(term);
			ft_strclr(buf);
		}
	}
	return (0);
}

