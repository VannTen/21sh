/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editor_checks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:16:49 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/28 11:51:36 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editor_defs.h"
#include "interactive_string_interface.h"
#include "libft.h"

/*
** Confirm line adds a newline at the end of the string (as do bash when
** pressing Enter key) then check if it correctly quoted.
** If it is not, it go down one line on screen and to the leftmost column
** (beginning of line)
*/

int		confirm_line(t_line_editor *line_editor)
{
	const char	quote_chars[] = "\"\'";
	int			quote_correct;
	size_t		move;

	ASSERT(ARRAY_LENGTH(quote_chars) == 3);
	quote_correct = 0;
	move = go_to_last_letter(line_editor->buffer);
	if (add_letter(line_editor->buffer, '\n') != NULL)
		quote_correct =
			int_str_state_of_quote(line_editor->buffer, quote_chars);
	else
		fatal();
	if (quote_chars[quote_correct] == '\0')
		return (validate_line(line_editor->buffer));
	else
	{
		move_cursor_relatively(line_editor->term, GO_DOWN, 1);
		move_begin_line(line_editor->term);
	}
	return (0);
}

t_bool	is_validated(t_line_editor const *line_editor)
{
	return (is_valid_line(line_editor->buffer));
}
