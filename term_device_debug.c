/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_device_debug.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 14:46:32 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/30 15:16:36 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_device_defs.h"
#include <stdarg.h>
#include <termcap.h>

int	term_debug(t_term_device *term, char const *fmt, ...)
{
	va_list	args;
	int		ret;
	size_t	ret_2;

	ft_putstr_fd(term->seq_send[SAVE_CURSOR], term->fd);
	move_begin_next_line(term);
	move_begin_next_line(term);
	move_begin_next_line(term);
	va_start(args, fmt);
	ret = ft_vdprintf(term->fd, fmt, &args);
	if (ret == 0)
		ret_2 = ret;
	else
		return (ret);
	va_end(args);
	ft_putstr_fd(term->seq_send[RESTORE_CURSOR], term->fd);
	return (ret);
}
