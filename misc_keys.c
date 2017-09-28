/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 16:38:13 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/28 16:54:29 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editor_defs.h"
#include "keys_functions_defs.h"
#include "term_device_interface.h"

int	function_key_1(t_line_editor *line_editor)
{
	move_cursor_relatively(line_editor->term, GO_RIGHT, 1);
	return (0);
}

int	function_key_2(t_line_editor *line_editor)
{
	move_cursor_relatively(line_editor->term, GO_LEFT, 1);
	return (0);
}
