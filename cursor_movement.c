/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 19:22:11 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/23 12:26:18 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_device_defs.h"
#include <termcap.h>
#include <unistd.h>

static int	cust_putchar(int c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
void	move_cursor_relatively(t_term_device *term,
		enum e_direction dir, size_t n_time)
{
	char	*cmd;
	const int	coord_change[NB_DIRECT][2] = {
		{1,0},
		{-1,0},
		{0,-1},
		{0,1}
	};

	cmd = tgetstr("cm", NULL);
	tputs(tgoto(cmd, term->cursor.x + (coord_change[dir][0] * n_time),
				term->cursor.y + (coord_change[dir][1] * n_time)),
			1, cust_putchar);
}
