/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editor_defs.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:26:49 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/27 10:08:27 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_EDITOR_DEFS_H
# define LINE_EDITOR_DEFS_H
# include "line_editor_interface.h"
# include "interactive_string_interface.h"
# include "term_device_interface.h"

struct	s_line_editor
{
	t_interact_str	*buffer;
	t_term_device	*term;
};

#endif
