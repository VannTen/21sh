/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_key_sequences.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 10:47:09 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/27 14:45:41 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editor_defs.h"
#include "interactive_string_interface.h"
#include "term_keys_interface.h"
#include "libft.h"
#include <unistd.h>

/*
** The last character of buf should only be sent if there is more than one
** character, otherwise, it should be saved. So if the index is 0 (= only one
** character present), increment it to 1 to consume that character
*/

static size_t	send_to_buffer(char *buf, t_line_editor *term, size_t nb_char)
{
	size_t	index;
	void	*ret;

	index = 0;
	if (nb_char == 0)
		nb_char++;
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
** search_for_sequence
**
** This function works this way :.
** It has an initial state where buf is empty (= the empty string), or contain
** one initial character.
** This slate translate into buf containing one character with a conditionnal.
** If there is matches for the first character read (there is some sequences
** which start with that character) the subroutines request more characters,
** storing them in buf, and using index to keep track.
** If a match is found, the corresping action is taken.
** If not, the characters are litterals, and send as so to the buffer, EXCEPT
** for the last one : indeed, it is the only one who do not match (it would have
** stopped before if not), but it could be part of another sequence.
** When the re
** This method avoids assumptions about the searched sequences, other than none
** is a subsequence of another.
**
** TODO : Add a timeout on sequence searching, aka, if part of a sequence is
** readed, but there is some interval before the continuation, it is in fact not
** a sequence. This could be accomplished with VMIN and VTIME settings in
** termios, but it could be tricky : there could be some overhead to relaunch a
** read every time it expires until the user type something.
*/

int				search_for_sequence(t_line_editor *term)
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
