/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:02:12 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/23 12:37:01 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editor_defs.h"
#include "interactive_string_interface.h"
#include <stdlib.h>

t_line_editor	*create_line_editor(int fd)
{
	t_line_editor *new;

	new = malloc(sizeof(t_line_editor));
	if (new != NULL)
	{
		new->term = create_term_device(fd);
		new->buffer = create_interact_str();
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
		destroy_term_device(&to_destroy->term);
		free(to_destroy);
		*line_editor = NULL;
	}
}
