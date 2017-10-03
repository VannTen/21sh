/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_break_rules_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 13:06:34 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/02 17:35:16 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token_defs.h"
#include "libft.h"

t_bool	new_operator(char **input, t_tokenizer *state, t_token *token)
{
	if (can_start_operator(**input)
			&& !is_quoted(**input, state))
	{
		if (token->type != TOKEN)
			state->delimited = TRUE;
		else
		{
			token->type = OPERATOR;
			token->size++;
			*input++;
		}
		return (TRUE);
	}
	else
		return (FALSE);
}

t_bool	blank(char **input, t_tokenizer *state, t_token *token)
{
	(void)token;
	if (is_blank(**input)
			&& !is_quoted(**input, state))
	{
		state->delimited = TRUE;
		*input++;
		return (TRUE);
	}
	else
		return (FALSE);
}

t_bool	append_to_word(char **input, t_tokenizer *state, t_token *token)
{
	if (token->type == WORD)
	{
		*input++;
		token->size++;
		return (TRUE);
	}
	else
		return (FALSE);
}

t_bool	comment(char **input, t_tokenizer *state, t_token *token)
{
	if (**input == '#'
			&& !is_quoted(**input, state))
	{
		while (**input != '\n')
			*input++;
		return (TRUE);
	}
	else
		return (FALSE);
}

t_bool	start_new_word(char **input, t_tokenizer *state, t_token *token)
{
	(void)state;
	token->type = WORD;
	token->size++;
	*input++;
	return (TRUE);
}
