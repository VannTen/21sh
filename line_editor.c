/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:02:12 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/21 19:06:27 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_actions_defs.h"
#include "interactive_string_interface.h"
#include <stdlib.h>

t_line_editor	*create_line_editor(int fd)
{
	t_line_editor *new;

	new = malloc(sizeof(t_line_editor));
	if (new != NULL)
	{
		new->term_fd = fd;
		new->buffer = create_interact_str();
		new->keys_cmd = generate_keys_cmd_sequences();
		new->seq_send = NULL;
	}
	return (new);
}

void			destroy_line_editor(t_line_editor **line_editor)
{
	t_line_editor	*to_destroy;

	to_destroy = *line_editor;
	if (to_destroy != NULL)
	{
		destroy_interact_str(&to_destroy->buffer);
	}
	free(to_destroy);
	*line_editor = NULL;
}
