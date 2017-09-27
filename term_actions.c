/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 10:45:04 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/20 12:33:12 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editor_defs.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

char	*term_act(void)
{
	t_line_editor	*term;
	char			*str;

	term = create_line_editor(STDIN_FILENO);
	if (term != NULL)
		search_for_sequence(term);
	str = get_full_string(term->buffer);
	destroy_line_editor(&term);
	return (str);
}
