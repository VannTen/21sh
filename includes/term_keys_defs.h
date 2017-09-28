/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_keys_defs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 18:26:13 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/28 16:48:20 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_KEYS_DEFS_H
# define TERM_KEYS_DEFS_H
# include "term_keys_interface.h"
# include "keys_functions_interface.h"

struct	s_key
{
	char			*str;
	t_term_action	action;
};

# define KEY_CODES_INIT\
		"kl",\
		"kr",\
		"ku",\
		"kd",\
		"kb",\
		"kD",\
		"kh",\
		"@7",\
		"kN",\
		"@8",\
		"k1",\
		"k2"

/*
** This if a temporary workaround for capabilites that are not working as
** expected, for unknown reasons (to me). Either it is a termios settings or
** something else. Will look into it when relevant
** "kb" : backspace, terminfo send "^M" string, Iterm actuallys sends "\177"
** (del characacter)
** "@8" (kent) : entry/send key. Terminfo entry is "\EOM", Iterm2 send simply a
** newline
*/

# ifndef NO_TEST
#  define KEY_CODES_OVERRIDE\
		NULL,\
		NULL,\
		NULL,\
		NULL,\
		"\177",\
		NULL,\
		NULL,\
		NULL,\
		"aaa",\
		"\n",\
		NULL,\
		NULL
# endif
# define KEY_ACTIONS_INIT\
		left_arrow,\
		right_arrow,\
		up_arrow,\
		down_arrow,\
		backspace,\
		delete,\
		home,\
		end,\
		bad_key,\
		enter_key,\
		function_key_1,\
		function_key_2
#endif
