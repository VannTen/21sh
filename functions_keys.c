/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:12:30 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/25 17:37:17 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys_functions_defs.h"
#include "term_actions_defs.h"
#include "term_device_interface.h"

int	delete(t_line_editor *term)
{
	if (del_letter(term->buffer))
	{
		suppress_character(term->term);
		return (0);
	}
	return (1);
}

int backspace(t_line_editor *term)
{
	if (left_arrow(term) == 0)
		return (delete(term));
	return (1);

}

int	home(t_line_editor *term)
{
	go_to_first_letter(term->buffer);
	move_begin_line(term->term);
	return (0);
}

int	end(t_line_editor *term)
{
	move_cursor_relatively(term->term, GO_RIGHT,
			go_to_last_letter(term->buffer));
	return (0);
}
