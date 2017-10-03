/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_break_rules_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 12:43:01 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/02 17:29:32 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token_defs.h"
#include "libft.h"

t_bool	end_of_input(char **input, t_tokenizer *state, t_token *token)
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

t_bool	append_to_op(char **input, t_tokenizer *state, t_token *token)
{
	if (token->type == OPERATOR
			&& is_not_quoted(**input, state)
			&& can_be_operator(*(*input - 1), **input, state))
	{
		token->size++;
		*input++;
		return (TRUE);
	}
	else
		return (FALSE);
}

t_bool	delimit_op(char **input, t_tokenizer *state, t_token *token)
{
	if (token->type == OPERATOR
			&& !can_be_operator(*(*input - 1), **input, state))
	{
		state->delimited = TRUE;
		return (TRUE);
	}
	else
		return (FALSE);
}

t_bool	quoting(char **input, t_tokenizer *state, t_token *token)
{
	enum e_quote_type	index;
	const char			quote_chars[] = "\\\'\"";

	(void)token;
	ASSERT(ARRAY_LENGTH(quote_chars) == NB_QUOTE_CHARACTERS);
	index = 0;
	while (quote_chars[index] != '\0')
	{
		if (**input == quote_chars[index])
		{
			state->quoting[index] = !state->quoting[index];
			return (TRUE);
		}
		index++;
	}
	return (FALSE);
}

t_bool	param_expansion(char **input, t_tokenizer *state, t_token *token)
{
	(void)input;
	(void)state;
	(void)token;
	return (FALSE);
}
