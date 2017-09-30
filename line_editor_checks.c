/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editor_checks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:16:49 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/30 17:49:00 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editor_defs.h"
#include "interactive_string_interface.h"
#include "term_device_interface.h"
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

size_t	would_go_beyond_edge(t_line_editor const *line_editor,
		enum e_edge edge, size_t nb_move)
{
	size_t	nb_column;
	size_t	current_line_position;

	nb_column = get_nb_column(line_editor->term) - 1;
	current_line_position =
		get_current_position(line_editor->buffer) % nb_column;
	term_debug(line_editor->term, "\n%zu %zu %zu %zu",
			get_current_position(line_editor->buffer),
				current_line_position, nb_move, nb_column);
	if (edge == RIGHT)
	{
		if (current_line_position + nb_move >= nb_column)
		{
			return (current_line_position + nb_move - nb_column + 1);
		}
		else
			return (0);
	}
	if (edge == LEFT)
	{
		if (current_line_position <= nb_move)
			return (nb_move - current_line_position + 1);
		else
			return (0);
	}
	return (0);
}

/*
** This function is useful to know when to work around the eat_newline_glitch
** See URL below for an explanation
** gnu.org/software/termutils/manual/termcap-1.3/html_mono/termcap.html#SEC27
*/

t_bool	check_wrap_and_do(t_line_editor *line_edit)
{
	if (would_go_beyond_edge(line_edit, RIGHT, 1))
	{
		move_cursor_relatively(line_edit->term, GO_DOWN, 1);
		move_begin_line(line_edit->term);
		return (TRUE);
	}
	return (FALSE);
}
