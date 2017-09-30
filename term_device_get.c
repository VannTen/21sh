/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_device_get.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 10:08:08 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/30 12:53:03 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_device_defs.h"

int		get_fd(t_term_device const *term)
{
	return (term->fd);
}

unsigned short	get_nb_column(t_term_device const *term)
{
		return (term->dimensions.ws_col);
}

t_bool			has_newline_glitch(t_term_device const *term)
{
	return (term->flags[EAT_NEWLINE_GLITCH]);
}
