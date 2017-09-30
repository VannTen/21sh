/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_device_interface.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 12:09:13 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/30 17:57:31 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_DEVICE_INTERFACE_H
# define TERM_DEVICE_INTERFACE_H
# include "term_keys_interface.h"
# include <stddef.h>

typedef struct s_term_device	t_term_device;

/*
** Ressources management
** Implementation file : term_device_init.c
*/

t_term_device	*create_term_device(int fd);
void			destroy_term_device(t_term_device **term);
int				set_device_size(t_term_device *term);

/*
** Named constant passed as parameters to function which expect a direction
** to move the cursor
*/

enum	e_direction
{
	GO_UP,
	GO_DOWN,
	GO_LEFT,
	GO_RIGHT,
	NB_DIRECT
};

/*
** Function to move cursor on the terminal
** Implementation file : cursor_movement.c
*/

void			move_cursor_relatively(t_term_device *term,
		enum e_direction dir, size_t n_time);
void			move_begin_line(t_term_device *term);
void			move_begin_next_line(t_term_device *term);
void			move_end_previous_line(t_term_device *term);

/*
** Insertion and deletion of characters
** Implemetation file : term_insert_del.c
*/

void			insert_character(t_term_device *term, char c);
void			suppress_character(t_term_device *term);

/*
** Various actions of the terminal
** Implementation file : term_device_actions.c
*/

void			ring_audible_bell(t_term_device *term);

/*
** Getters
** Implementation file : term_device_get.c
*/

int				get_fd(t_term_device const *term);
unsigned short	get_nb_column(t_term_device const *term);
t_bool			has_newline_glitch(t_term_device const *term);

/*
** Processing terminal input
** Implementation file : term_device_input.c
*/

t_term_action	find_key_sequence(t_term_device const *buffer, char *buf,
		size_t	*index);

/*
** Checks on positionning
** Implementation file : term_device_checks.c
*/

size_t			is_beyond_edge(t_term_device const *term,
		size_t abs_old_position, enum e_edge edge, size_t nb_move);
/*
** Debug wihtout scrambling the current state of the screen
** Implementation file : term_device_debug.c
*/

int				term_debug(t_term_device *term, char const *fmt, ...)
	__attribute__ ((format (printf, 2, 3)));

#endif
