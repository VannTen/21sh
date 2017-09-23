/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_device_defs.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 12:07:19 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/23 12:20:39 by mgautier         ###   ########.fr       */
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
};


#endif
