/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 19:22:11 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/25 13:52:46 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_device_defs.h"
#include "libft.h"
#include <termcap.h>
#include <unistd.h>

void	move_cursor_relatively(t_term_device *term,
		enum e_direction dir, size_t n_time)
{
	const enum e_term_string_send	cmd[] = {
		CURSOR_UP,
		CURSOR_DOWN,
		CURSOR_LEFT,
		CURSOR_RIGHT
	};

	(void)n_time;
	tputs(term->seq_send[cmd[dir]], 1, term->putchar);
}
