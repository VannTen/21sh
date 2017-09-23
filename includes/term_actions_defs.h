/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_actions_defs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:26:49 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/23 12:11:16 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_ACTIONS_DEFS_H
# define TERM_ACTIONS_DEFS_H
# include "term_actions_interface.h"
# include "interactive_string_interface.h"
# include "term_device_interface.h"

struct	s_line_editor
{
	t_interact_str	*buffer;
	t_term_device	*term;
};

#endif
