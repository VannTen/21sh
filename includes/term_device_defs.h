/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_device_defs.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 12:07:19 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/25 00:43:20 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_DEVICE_DEFS_H
# define TERM_DEVICE_DEFS_H
# include "term_device_interface.h"
# include "term_actions_interface.h"


typedef struct s_position		t_position;

struct	s_keypad_cmd
{
	char			*str;
	t_term_action	action;
};

struct	s_position
{
	int	x;
	int y;
};


struct	s_term_device
{
	int				fd;
	t_keypad_cmd	*keys_cmd;
	char			**seq_send;
	t_position		cursor;
	int				(*putchar)(int);
};

enum	e_term_string_send
{
	CURSOR_LEFT,
	CURSOR_RIGHT,
	CURSOR_UP,
	CURSOR_DOWN,
	KS,
	KE,
	INSERT_CHAR,
	INSERT_MODE,
	INSERT_PADDING,
	EXIT_INSERT,
	DELETE_MODE,
	DELETE_CHAR,
	EXIT_DELETE,
	NB_TERM_STRING
};

# define CMD_STRING_PATTERN \
	"le",\
	"nd",\
	"up",\
	"do",\
	"ks",\
	"ke",\
	"ic",\
	"im",\
	"ip",\
	"ei",\
	"dm",\
	"dc",\
	"ec"

/*
** Internal ressources management of termcaps strings
** Implementation file : term_string_codes.c
*/

char			**create_cmd_strings(void);
void			destroy_cmd_strings(char ***cmd_strings);
t_keypad_cmd	*generate_keys_cmd_sequences(void);
void			destroy_keys_cmd_sequences(t_keypad_cmd **sequences);

#endif
