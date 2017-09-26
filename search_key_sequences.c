/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_key_sequences.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 10:47:09 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/26 17:43:47 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_actions_defs.h"
#include "interactive_string_interface.h"
#include "term_keys_interface.h"
#include "libft.h"
#include <unistd.h>

static size_t	send_to_buffer(char *buf, t_line_editor *term, size_t nb_char)
{
	size_t	index;
	void	*ret;

	index = 0;
	ret = &index;
	while (index <= nb_char && ret != NULL)
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
		index = 0;
		if (buf[0] == '\0')
			read(get_fd(term->term), &buf, 1);
		buf[1] = '\0';
		key_to_do = find_key_sequence(term->term, buf, &index);
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

