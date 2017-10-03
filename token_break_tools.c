/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_break_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 09:44:40 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/03 14:04:41 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token_defs.h"
#include "libft.h"

t_bool	is_end_of_input(char input, t_tokenizer const *state)
{
	return (input == '\0' && (TRUE || !is_quoted(input, state)));
}

t_bool	is_quoted(char input, t_tokenizer const *state)
{
	enum e_quote_type	index;
	const char			quote_chars[] = QUOTE_CHARACTERS_STR;

	ASSERT(ARRAY_LENGTH(quote_chars) - 1 == NB_QUOTE_CHARACTERS);
	index = 0;
	return ((state->quoting[BACKSLASH] && input != '\n')
			|| (state->quoting[SQUOTE] && input != '\'')
			|| (state->quoting[DQUOTE] && ft_strchr("\"`$\\", input) == NULL));
}

/*
** TODO : The operators list used in these two functions could be defined in
** only one place (would be useful for not defining all of them).
** + they will probably be needed elsewhere
*/

t_bool	can_be_operator(char first, char second, t_token const *token)
{
	char	*operators[] = {
		/* Redirection operators */
		"<", ">", ">|", "<<", ">>", "<&", ">&", "<<-", "<>",
		/* Control operators */
		"&", "&&", "(", ")", ";", ";;", "\n", "|", "||"
	};
	size_t	index;
	size_t	index_token;

	index_token = token->size - 1;
	index = 0;
	while (index < ARRAY_LENGTH(operators))
	{
		if (!(ft_strlen(operators[index]) < token->size)
				&& first == operators[index][index_token]
				&& second == operators[index][index_token + 1])
			return (TRUE);
		index++;
	}
	return (FALSE);
}

t_bool	can_start_operator(char c)
{
	const char	*operators[] = {
		/* Redirection operators */
		"<", ">", ">|", "<<", ">>", "<&", ">&", "<<-", "<>",
		/* Control operators */
		"&", "&&", "(", ")", ";", ";;", "\n", "|", "||"
	};
	size_t	index;

	index = 0;
		while (index < ARRAY_LENGTH(operators))
		{
			if (operators[index][0] == c)
				return (TRUE);
			index++;
		}
	return (FALSE);
}

/*
** TODO : should be defined by the current locale, not manually
*/

t_bool	is_blank(char input)
{
	return (input == ' ' || input == '\t');
}
