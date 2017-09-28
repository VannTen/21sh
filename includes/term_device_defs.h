/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_device_defs.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 12:07:19 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/28 14:23:10 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_DEVICE_DEFS_H
# define TERM_DEVICE_DEFS_H
# include "term_device_interface.h"
# include "line_editor_interface.h"
# include "term_keys_interface.h"
# include <sys/ioctl.h>

/*
**
** For reference, the struct winsize is defined that way in <sys/ioctl.h>
**
**	struct winsize {
**		unsigned short	ws_row;		* rows, in characters *
**		unsigned short	ws_col;		* columns, in characters *
**		unsigned short	ws_xpixel;	* horizontal size, pixels *
**		unsigned short	ws_ypixel;	* vertical size, pixels *
**		};
*/

struct	s_term_device
{
	int				fd;
	t_key			*keys_cmd;
	char			**seq_send;
	int				(*putchar)(int);
	struct winsize	dimensions;
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
	BEGIN_LINE,
	RING_BELL,
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
	"ec",\
	"cr",\
	"bl"

/*
** Internal ressources management of termcaps strings
** Implementation file : term_string_codes.c
*/

char	**create_cmd_strings(void);
void	destroy_cmd_strings(char ***cmd_strings);

#endif
