/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_string_codes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 16:06:35 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/25 00:37:12 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_device_defs.h"
#include "libft.h"
#include <termcap.h>
#include <stdlib.h>

int	left_arrow(t_line_editor *term);
int right_arrow(t_line_editor *term);
int up_arrow(t_line_editor *term);
int down_arrow(t_line_editor *term);
int	backspace(t_line_editor *term);
int	delete(t_line_editor *term);
int ft_a(t_line_editor *term);

char	**create_cmd_strings(void)
{
	static char				*cap_names[] = {CMD_STRING_PATTERN};
	enum e_term_string_send	index;
	char					**cmd_strings;

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

void	destroy_cmd_strings(char ***cmd_strings)
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

t_keypad_cmd	*generate_keys_cmd_sequences(void)
{
	static char				*key_codes[] = {
		"kl",
		"kr",
		"ku",
		"kd",
		"kb",
		"kD"
	};
	static t_term_action	actions[] = {
		left_arrow,
		right_arrow,
		up_arrow,
		down_arrow,
		backspace,
		delete
	};
	t_keypad_cmd			*key_sequences;
	size_t					index;

	index = 0;
	key_sequences = malloc((sizeof(key_codes) / sizeof(char*) + 1)
			* sizeof(t_keypad_cmd));
	if (key_sequences != NULL)
	{
		while (index < sizeof(key_codes) / sizeof(char*))
		{
			key_sequences[index].str = tgetstr(key_codes[index], NULL);
			key_sequences[index].action = actions[index];
			index++;
		}
		key_sequences[index].str = NULL;
	}
	return (key_sequences);
}

void			destroy_keys_cmd_sequences(t_keypad_cmd **sequences)
{
	size_t			index;
	t_keypad_cmd	*to_destroy;

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
