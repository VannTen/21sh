/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_string_codes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 16:06:35 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/28 18:32:45 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_device_defs.h"
#include "keys_functions_interface.h"
#include "libft.h"
#include <termcap.h>
#include <stdlib.h>

char			**create_cmd_strings(void)
{
	static char				*cap_names[] = {CMD_STRING_PATTERN};
	enum e_term_string_send	index;
	char					**cmd_strings;

	ASSERT(ARRAY_LENGTH(cap_names) == NB_TERM_STRING);
	cmd_strings = malloc(NB_TERM_STRING * sizeof(char*));
	if (cmd_strings != NULL)
	{
		index = 0;
		while (index < NB_TERM_STRING)
		{
			cmd_strings[index] = tgetstr(cap_names[index], NULL);
			index++;
		}
	}
	return (cmd_strings);
}

void			destroy_cmd_strings(char ***cmd_strings)
{
	size_t	index;
	char	**to_destroy;

	to_destroy = *cmd_strings;
	if (to_destroy != NULL)
	{
		index = 0;
		while (index < NB_TERM_STRING)
		{
			to_destroy[index] = NULL;
			index++;
		}
		free(to_destroy);
		*cmd_strings = NULL;
	}
}

t_bool			*create_cap_flags(void)
{
	static char		*cap_names[] = {BOOL_CAP_INIT};
	enum e_bool_cap	index;
	t_bool			*cap_states;

	ASSERT(ARRAY_LENGTH(cap_names) == NB_BOOL_CAP);
	cap_states = malloc(NB_BOOL_CAP * sizeof(t_bool));
	if (cap_states != NULL)
	{
		index = 0;
		while (index < NB_BOOL_CAP)
		{
			cap_states[index] = tgetflag(cap_names[index]);
			index++;
		}
	}
	return (cap_states);
}
