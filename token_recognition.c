/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_recognition.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 12:16:54 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/03 13:55:24 by mgautier         ###   ########.fr       */
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

t_token	*create_token()
{
	t_token *new;

	new = malloc(sizeof(t_token));
	if (new != NULL)
		init_token(new);
	return (new);
}

void	destroy_token(t_token **token)
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
	init_bool_array(tokenizer->quoting, NB_QUOTE_CHARACTERS, FALSE);
}

t_token	*recognize_token(char const **input)
{
	t_token_rule const	rules[] = {end_of_input, append_to_op, delimit_op,
		quoting, param_expansion, new_operator, blank, append_to_word, comment,
		start_new_word};
	size_t				index_rules;
	t_token				*new_token;
	t_tokenizer			state;
	t_bool				backslash_reset;

	init_tokenizer(&state);
	new_token = create_token();
	while (new_token->size == 0)
	{
		new_token->type = TOKEN;
		state.delimited = FALSE;
		new_token->start = *input;
		backslash_reset = FALSE;
		while (!state.delimited)
		{
			index_rules = 0;
			if (state.quoting[BACKSLASH])
				backslash_reset = TRUE;
			while (!rules[index_rules](input, &state, new_token))
				index_rules++;
			if (backslash_reset)
				state.quoting[BACKSLASH] = FALSE;
		}
	}
	return (new_token);
}
