/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_actions_defs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:26:49 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/19 16:06:19 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_ACTIONS_DEFS_H
# define TERM_ACTIONS_DEFS_H
# include "term_actions_interface.h"
# include "interactive_string_interface.h"

struct	s_keypad_cmd
{
	char			*str;
	char			*seq_sent;
	t_term_action	action;
};

struct	s_line_editor
{
	t_interact_str		*buffer;
	int					term_fd;
	t_keypad_cmd		*keys_cmd;
	char				**seq_send;
};

#endif
