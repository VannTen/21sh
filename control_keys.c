/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:14:25 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/27 11:31:34 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys_functions_defs.h"

int	enter_key(t_line_editor *line_editor)
{
	return (confirm_line(line_editor));
}
