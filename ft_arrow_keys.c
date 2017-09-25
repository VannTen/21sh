/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrow_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 13:45:23 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/25 15:01:21 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_actions_defs.h"
#include "term_device_interface.h"
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
		move_cursor_relatively(term->term, GO_RIGHT, 1);
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

int	ft_a(t_line_editor *term)
{
	(void)term;

	ft_putstr("Triple A");

	return (0);
}
