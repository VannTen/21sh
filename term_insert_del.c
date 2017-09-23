/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_insert_del.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 16:00:26 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/23 17:28:35 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_device_defs.h"

void	insert_character(t_term_device *term, char c)
{
	tputs(term->keys_cmd[INSERT_MODE], 1, term->putchar);
	tputs(term->keys_cmd[INSERT_CHAR], 1, term->putchar);
	term->putchar(c);
	tputs(term->keys_cmd[INSERT_PADDING], 1, term->putchar);
	tputs(term->keys_cmd[EXIT_INSERT], 1, term->putchar);
	move_cursor_relatively(term, GO_RIGHT, 1);
}

void	delete_character(t_term_device *term)
{
	tputs(term->keys_cmd[DELETE_MODE], 1, term->putchar);
	tputs(term->keys_cmd[DELETE_CHAR], 1, term->putchar);
	tputs(term->keys_cmd[EXIT_CHAR], 1, term->putchar);
}
