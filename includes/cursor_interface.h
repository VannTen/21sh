/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_interface.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 19:26:01 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/21 19:28:19 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSOR_INTERFACE_H
# define CURSOR_INTERFACE_H


/*
** Named constant passed as parameters to function which expect a direction
** to move the cursor
*/

enum	e_direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

/*
** Function to move cursor on the terminal
** Implementation file : cursor_movement.c
*/

void	move_cursor_relatively(int fd, enum e_direction dir, size_t	n_time);


#endif
