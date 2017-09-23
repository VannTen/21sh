/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_device_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 12:12:41 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/23 12:37:15 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_device_defs.h"
#include <termcap.h>
#include <stdlib.h>


int	left_arrow(t_line_editor *term);
int right_arrow(t_line_editor *term);
int up_arrow(t_line_editor *term);
int down_arrow(t_line_editor *term);
int ft_a(t_line_editor *term);

static t_keypad_cmd	*generate_keys_cmd_sequences(void)
{
	static char				*key_codes[] = {
		"kl",
		"kr",
		"ku",
		"kd",
		NULL
	};
	static t_term_action	actions[] = {
		left_arrow,
		right_arrow,
		up_arrow,
		down_arrow,
		NULL
	};
	static t_keypad_cmd	key_sequences[6];
	size_t				index;

	index = 0;
	while (index < 4)
	{
		key_sequences[index].str = tgetstr(key_codes[index], NULL);
		key_sequences[index].action = actions[index];
		index++;
	}
	key_sequences[index].str = "aaa";
	key_sequences[index].action = ft_a;
	key_sequences[index + 1].str = NULL;

	return (key_sequences);
}

t_term_device	*create_term_device(int fd)
{
	t_term_device	*new;

	new = malloc(sizeof(t_term_device));
	if (new != NULL)
	{
		new->fd = fd;
		new->keys_cmd = generate_keys_cmd_sequences();
		new->seq_send = NULL;
		new->cursor.x = 0;
		new->cursor.y = 0;
	}
	return (new);
}

void			destroy_term_device(t_term_device **term)
{
	t_term_device	*to_destroy;

	to_destroy = *term;
	if (to_destroy != NULL)
	{
		to_destroy->fd = 0;
		to_destroy->keys_cmd = NULL;
		to_destroy->seq_send = NULL;
		to_destroy->cursor.x = 0;
		to_destroy->cursor.y = 0;
		free(to_destroy);
		*term = NULL;
	}
}
