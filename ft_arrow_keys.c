/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrow_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 13:45:23 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/28 16:23:12 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editor_defs.h"
#include "term_device_interface.h"
#include "interactive_string_interface.h"
#include "libft.h"
#include <termcap.h>
#include <stddef.h>

int	left_arrow(t_line_editor *term)
{
	if (back_x_letter(term->buffer, 1) != 0)
	{
		move_cursor_relatively(term->term, GO_LEFT, 1);
		return (0);
	}
	return (1);
}

int	right_arrow(t_line_editor *term)
{
	if (forward_x_letter(term->buffer, 1) != 0)
	{
		if (would_go_beyond_edge(term, RIGHT, 1))
		{
			move_cursor_relatively(term->term, GO_DOWN, 1);
			move_begin_line(term->term);
		ft_printf("Error");
		}
		else
			move_cursor_relatively(term->term, GO_RIGHT, 1);
	}
	return (0);
}

int	up_arrow(t_line_editor *term)
{
	(void)term;
	return (ft_printf("\nup arrow\n"));
}

int	down_arrow(t_line_editor *term)
{
	(void)term;
	return (ft_printf("\ndown arrow\n"));
}
