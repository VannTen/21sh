/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_device_actions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 12:29:30 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/26 12:38:45 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_device_defs.h"
#include <termcap.h>

void	ring_audible_bell(t_term_device *term)
{
	tputs(term->seq_send[RING_BELL], 1, term->putchar);
}
