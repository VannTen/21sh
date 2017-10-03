/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_break_rules_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 12:43:01 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/03 13:38:42 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token_defs.h"
#include "libft.h"

t_bool	end_of_input(char const **input, t_tokenizer *state, t_token *token)
{
	(void)token;
	if (is_end_of_input(**input, state))
	{
		state->delimited = TRUE;
		return (TRUE);
	}
	else
		return (FALSE);
}

t_bool	append_to_op(char const **input, t_tokenizer *state, t_token *token)
{
	if (token->type == OPERATOR
			&& !is_quoted(**input, state)
			&& can_be_operator(*(*input - 1), **input, token))
	{
		token->size++;
		(*input)++;
		return (TRUE);
	}
	else
		return (FALSE);
}

t_bool	delimit_op(char const **input, t_tokenizer *state, t_token *token)
{
	if (token->type == OPERATOR
			&& !can_be_operator(*(*input - 1), **input, token))
	{
		state->delimited = TRUE;
		return (TRUE);
	}
	else
		return (FALSE);
}

t_bool	quoting(char const **input, t_tokenizer *state, t_token *token)
{
	enum e_quote_type	index;
	const char			quote_chars[] = QUOTE_CHARACTERS_STR;

	(void)token;
	ASSERT(ARRAY_LENGTH(quote_chars) - 1 == NB_QUOTE_CHARACTERS);
	index = 0;
	if (!is_quoted(**input, state))
	{
		while (quote_chars[index] != '\0')
		{
			if (**input == quote_chars[index])
			{
				state->quoting[index] = !state->quoting[index];
				(*input)++;
				token->size++;
				return (TRUE);
			}
			index++;
		}
	}
	return (FALSE);
}

t_bool	param_expansion(char const **input, t_tokenizer *state, t_token *token)
{
	(void)input;
	(void)state;
	(void)token;
	return (FALSE);
}
