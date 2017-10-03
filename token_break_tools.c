/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_break_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 09:44:40 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/03 11:05:01 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token_defs.h"
#include "libft.h"

t_bool	is_end_of_input(char input, t_tokenizer const *state)
{
	return (input == '\n' && !is_quoted(input, state));
}

t_bool	is_quoted(char input, t_tokenizer const *state)
{
	return (state->quoting[BACKSLASH]
			|| state->quoting[SQUOTE]
			|| state->quoting[DQUOTE] && ft_strchr("`$\\", input) == NULL);
}

t_bool	can_be_operator(char first, char second, t_tokenizer const *state)
{
	char	operators[][] = {
		/* Redirection operators */
		"<", ">", ">|", "<<", ">>", "<&", ">&", "<<-", "<>",
		/* Control operators */
		"&", "&&", "(", ")", ";", ";;", "\n", "|", "||"
	};
	size_t	index;

	index = 0;
}

t_bool	can_start_operator(char c, t_tokenizer const *state)
{
	const char	operators[][] = {
		/* Redirection operators */
		"<", ">", ">|", "<<", ">>", "<&", ">&", "<<-", "<>",
		/* Control operators */
		"&", "&&", "(", ")", ";", ";;", "\n", "|", "||"
	};
	size_t	index;

	index = 0;
	if (!is_quoted(c, state))
	{
		while (index < ARRAY_SIZE(operators))
		{
			if (operators[index][0] == c)
				return (TRUE);
			index++;
		}
	}
	return (FALSE);
}
