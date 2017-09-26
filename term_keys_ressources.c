/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_key_ressources.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 09:55:17 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/26 13:08:08 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_keys_defs.h"
#include <termcap.h>
#include <stdlib.h>

t_key	*generate_term_keys(void)
{
	static char				*key_codes[] = {KEY_CODES_INIT};
#ifndef NO_TEST
	static char				*key_codes_over[] = {KEY_CODES_OVERRIDE};
#endif
	static t_term_action	actions[] = {KEY_ACTIONS_INIT};
	t_key					*key_sequences;
	size_t					index;

	index = 0;
	key_sequences = malloc((sizeof(key_codes) / sizeof(char*) + 1)
			* sizeof(t_key));
	if (key_sequences != NULL)
	{
		while (index < sizeof(key_codes) / sizeof(char*))
		{
#ifndef NO_TEST
			if (key_codes_over[index] != NULL)
				key_sequences[index].str = key_codes_over[index];
			else
#endif
				key_sequences[index].str = tgetstr(key_codes[index], NULL);
			key_sequences[index].action = actions[index];
			index++;
		}
		key_sequences[index].str = NULL;
	}
	return (key_sequences);
}

void	destroy_term_keys(t_key **sequences)
{
	size_t			index;
	t_key			*to_destroy;

	to_destroy = *sequences;
	if (to_destroy != NULL)
	{
		index = 0;
		while (to_destroy[index].str != NULL)
		{
			to_destroy[index].str = NULL;
			to_destroy[index].action = NULL;
			index++;
		}
		free(to_destroy);
		*sequences = NULL;
	}
}
