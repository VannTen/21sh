/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_interface.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 10:49:41 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/07 12:23:32 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOL_INTERFACE_H
# define SYMBOL_INTERFACE_H

typedef struct s_symbol	t_symbol;

typedef enum	e_symbol_type
{
	/* Terminals */
	WORD,
	ASSIGNEMENT,
	NAME,
	NEWLINE,
	IO_NUMBER,
	AND_IF,
	OR_IF,
	DSEMI,
	DLESS,
	DGREAT,
	LESSAND,
	GREATAND,
	LESSGREAT,
	DLESSDASH,
	CLOBBER,
	AND,
	SEMI,
	GREAT,
	LESS,
	IF,
	THEN,
	ELSE,
	ELIF,
	FI,
	DO,
	DONE,
	CASE,
	ESAC,
	WHILE,
	UNTIL,
	FOR,
	LBRACE,
	RBRACE,
	BANG,
	IN,
	EMPTY,
	/* Nonterminals */
	SEQUENTIAL_SEP,
	SEPARATOR,
	SEPARATOR_OP,
	LINEBREAK,
	NEWLINE_LIST,
	NB_SYMBOLS
}				t_symbol_type;



#endif
