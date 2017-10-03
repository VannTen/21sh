/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_defs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 12:18:05 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/03 13:34:47 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_DEFS_H
# define TOKEN_DEFS_H
# include "token_interface.h"
# include "libft.h"

typedef struct	s_tokenizer	t_tokenizer;
typedef t_bool	(*t_token_rule)(char const **input,
		t_tokenizer *state, t_token *token);

enum	e_token_type
{
	TOKEN,
	OPERATOR,
	WORD
};

typedef	enum e_token_type	t_token_type;

/*
** A token is constructed by the tokenizer breaking the input.
** type is the token type, listed in the e_token_type enum above
** start is the adresse if the first char included in the token
** Size is the number of characters, starting from start, which form the token
**
** So a token with a size of 0 DOES NOT include start.
*/

struct s_token
{
	t_token_type	type;
	char const		*start;
	size_t			size;
};

enum e_quote_type
{
	BACKSLASH,
	SQUOTE,
	DQUOTE,
	NB_QUOTE_CHARACTERS
};

# define QUOTE_CHARACTERS_STR "\\\'\""

struct s_tokenizer
{
	t_bool	delimited;
	t_bool	quoting[NB_QUOTE_CHARACTERS];
};

/*
** Tokenizer internals, implementing the token delimitation rules described in
** section 2.3 of the document "Shell Command Language" of POSIX.
** pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_03
** Implementation files : token_break_rules_1.c & token_break_rules_2.c
*/

t_bool	end_of_input(char const **input, t_tokenizer *state, t_token *token);
t_bool	append_to_op(char const **input, t_tokenizer *state, t_token *token);
t_bool	delimit_op(char const **input, t_tokenizer *state, t_token *token);
t_bool	quoting(char const **input, t_tokenizer *state, t_token *token);
t_bool	param_expansion(char const **input, t_tokenizer *state, t_token *token);
t_bool	new_operator(char const **input, t_tokenizer *state, t_token *token);
t_bool	blank(char const **input, t_tokenizer *state, t_token *token);
t_bool	append_to_word(char const **input, t_tokenizer *state, t_token *token);
t_bool	comment(char const **input, t_tokenizer *state, t_token *token);
t_bool	start_new_word(char const **input, t_tokenizer *state, t_token *token);

/*
** Tokenizer tools (used by the above rules)
** Implementation file : token_break_tools.c
*/

t_bool	is_end_of_input(char input, t_tokenizer const *state);
t_bool	is_quoted(char input, t_tokenizer const *state);
t_bool	can_be_operator(char first, char second, t_token const *token);
t_bool	can_start_operator(char c);
t_bool	is_blank(char input);

#endif
