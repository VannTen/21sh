/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_device_checks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 17:13:58 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/30 18:05:28 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_device_defs.h"

size_t	is_beyond_edge(t_term_device const *term,
		size_t abs_old_position, enum e_edge edge, size_t nb_move)
{
	size_t	old_position;

	old_position = abs_old_position % term->dimensions.ws_col;

	if (edge == RIGHT)
	{
		if (old_position + nb_move >= term->dimensions.ws_col)
		{
			return (old_position + nb_move
					- term->dimensions.ws_col
					+ 1);
		}
		else
			return (0);
	}
	if (edge == LEFT)
	{
		if (old_position < nb_move)
			return (nb_move - old_position + 1);
		else
			return (0);
	}
	return (0);
}
