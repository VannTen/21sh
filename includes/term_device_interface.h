/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_device_interface.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 12:09:13 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/25 00:31:19 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_DEVICE_INTERFACE_H
# define TERM_DEVICE_INTERFACE_H
# include <stddef.h>

typedef struct s_term_device	t_term_device;
typedef struct s_keypad_cmd		t_keypad_cmd;


/*
** Ressources management
** Implementation file : term_device_init.c
*/

t_term_device	*create_term_device(int fd);
void			destroy_term_device(t_term_device **term);

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

void	move_cursor_relatively(t_term_device *term,
		enum e_direction dir, size_t n_time);

/*
** Insertion and deletion of characters
** Implemetation file : term_insert_del.c
*/

void	insert_character(t_term_device *term, char c);
void	suppress_character(t_term_device *term);

#endif
