/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_recognition.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 12:16:54 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/02 17:08:32 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token_defs.h"
#include <stdlib.h>

void	init_token(t_token *token)
{
	token->type = TOKEN;
	token->start = NULL;
	token->size = 0;
}

t_token	*create_token();
{
	t_token *new;

	new = malloc(sizeof(t_token));
	if (new != NULL)
		init_token(new);
	return (new);
}

void	**destroy_token(t_token **token)
{
	t_token	*to_destroy;

	to_destroy = *token;
	if (to_destroy != NULL)
	{
		init_token(to_destroy);
		free(to_destroy);
		*token = NULL;
	}
}

/*
** Implementing section 2.3 of POSIX "Shell Command Language"
*/

void	init_tokenizer(t_tokenizer *tokenizer)
{
	tokenizer->delimited = FALSE;
	init_bool_array(&tokenizer->quoting, NB_QUOTE_CHARACTERS, FALSE);
}

t_token	*recognize_token(char const **input)
{
	const t_token_rule	rules[] = {end_of_input, append_to_op, delimit_op,
		quoting, param_expansion, new_operator, blank, append_to_word, comment,
		start_new_word};
	size_t				index_rules;
	t_token				*new_token;
	t_tokenizer			state;

	init_tokenizer(&state);
	new_token = create_token();
	new_token->start = *input;
	while (new_token->size = 0)
	{
		token->type = TOKEN;
		while (!state->delimited)
		{
			index_rules = 0;
			while (!rules[index](input, state, new_token))
				index_rules++;
		}
	}
	return (new_token);
}
