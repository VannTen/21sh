/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 19:22:11 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/23 14:51:34 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_device_defs.h"
#include "libft.h"
#include <termcap.h>
#include <unistd.h>

static int	cust_putchar(int c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
void	move_cursor_relatively(t_term_device *term,
		enum e_direction dir, size_t n_time)
{
	char	*cmd[] = {
		"up",
		"do",
		"le",
		"nd"
	};

	(void)term;
	(void)n_time;

	tputs(tgetstr(cmd[dir], NULL), 1, cust_putchar);
}
