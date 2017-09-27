/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_insert_del.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 16:00:26 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/25 00:45:00 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_device_defs.h"
#include <termcap.h>

void	insert_character(t_term_device *term, char c)
{
	if (term->seq_send[INSERT_MODE] != NULL)
		tputs(term->seq_send[INSERT_MODE], 1, term->putchar);
	if (term->seq_send[INSERT_CHAR] != NULL)
		tputs(term->seq_send[INSERT_CHAR], 1, term->putchar);
	term->putchar(c);
	tputs(term->seq_send[INSERT_PADDING], 1, term->putchar);
	if (term->seq_send[EXIT_INSERT] != NULL)
		tputs(term->seq_send[EXIT_INSERT], 1, term->putchar);
}

void	suppress_character(t_term_device *term)
{
	tputs(term->seq_send[DELETE_CHAR], 1, term->putchar);
}
