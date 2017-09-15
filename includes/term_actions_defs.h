/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_actions_defs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:26:49 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/11 13:30:38 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_ACTIONS_DEFS_H
# define TERM_ACTIONS_DEFS_H
# include "term_actions_interface.h"

struct	s_keypad_cmd_pattern
{
	char	*term_cap_received;
	char	*term_cap_sent;
	int		(*perform_intern)(t_interact_str *buf);
};

struct	s_keypad_cmd
{
	char	*seq_received;
	char	*seq_sent;
	int		(*perform_intern)(t_interact_str *buf);
};

#endif