/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editor_checks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:16:49 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/27 11:43:19 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editor_defs.h"
#include "interactive_string_interface.h"
#include "libft.h"

int		confirm_line(t_line_editor *line_editor)
{
	return (validate_line(line_editor->buffer));
}

t_bool	is_validated(t_line_editor const *line_editor)
{
	return (is_valid_line(line_editor->buffer));
}
