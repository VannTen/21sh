/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 19:22:11 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/28 11:53:32 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_device_defs.h"
#include "libft.h"
#include <termcap.h>
#include <unistd.h>

/*
** TODO:
**
** For vertical motion, use something else than the "do" and "up" capabilities if
** on the bottom or top off the screen (bottom is probably more of a concern in
** our case. According to termcap manual, that could cause undefined behavior.
** It is unclear in the terminfo manual if this is still the case, but better
** safe than sorry
*/

void	move_cursor_relatively(t_term_device *term,
		enum e_direction dir, size_t n_time)
{
	const enum e_term_string_send	cmd[] = {
		CURSOR_UP,
		CURSOR_DOWN,
		CURSOR_LEFT,
		CURSOR_RIGHT
	};
	size_t							times;

	times = 0;
	while (times < n_time)
	{
		tputs(term->seq_send[cmd[dir]], 1, term->putchar);
		times++;
	}
}

void	move_begin_line(t_term_device *term)
{
	tputs(term->seq_send[BEGIN_LINE], 1, term->putchar);
}
