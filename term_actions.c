/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 10:45:04 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/19 16:43:34 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_actions_defs.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

int	term_act(void)
{
	t_line_editor	*term;

	term = create_line_editor(STDIN_FILENO);
	if (term != NULL)
		search_for_sequence(term);
	return (1);
}
