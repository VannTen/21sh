/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrow_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 13:45:23 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/21 19:28:54 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_actions_defs.h"
#include "cursor_interface.h"
#include "libft.h"
#include <termcap.h>
#include <stddef.h>

static int	left_arrow(t_line_editor *term)
{
	if (back_x_letter(term->buffer, 1) != 0)
		move_cursor_relatively(term->term_fd, LEFT, 1);
	return (ft_printf("\nleft arrow\n"));
}

static int	right_arrow(t_line_editor *term)
{
	if (back_x_letter(term->buffer, 1) != 0)
		move_cursor_relatively(term->term_fd, LEFT, 1);
	return (ft_printf("\nright arrow\n"));
}

static int	up_arrow(t_line_editor *term)
{
	(void)term;
	return (ft_printf("\nup arrow\n"));
}

static int	down_arrow(t_line_editor *term)
{
	(void)term;
	return (ft_printf("\ndown arrow\n"));
}

static int	ft_a(t_line_editor *term)
{
	(void)term;

	ft_putstr("Triple A");

	return (0);
}
t_keypad_cmd	*generate_keys_cmd_sequences(void)
{
	static char				*key_codes[] = {
		"kl",
		"kr",
		"ku",
		"kd",
		NULL
	};
	static t_term_action	actions[] = {
		left_arrow,
		right_arrow,
		up_arrow,
		down_arrow,
		NULL
	};
	static t_keypad_cmd	key_sequences[6];
	size_t				index;

	index = 0;
	while (index < 4)
	{
		key_sequences[index].str = tgetstr(key_codes[index], NULL);
		key_sequences[index].action = actions[index];
		index++;
	}
	key_sequences[index].str = "aaa";
	key_sequences[index].action = ft_a;
	key_sequences[index + 1].str = NULL;

	return (key_sequences);
}
