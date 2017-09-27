/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive_string_defs.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 09:38:43 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/27 11:45:06 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERACTIVE_STRING_DEFS_H
# define INTERACTIVE_STRING_DEFS_H
# include "interactive_string_interface.h"
# include "libft.h"

typedef struct s_str_link	t_str_link;

struct		s_str_link
{
	struct s_str_link	*before;
	struct s_str_link	*after;
	char				letter;
};

struct		s_interact_str
{
	struct s_str_link	*begin;
	struct s_str_link	*end;
	struct s_str_link	*current;
	size_t				size;
	size_t				index;
	t_bool				is_valid_line;
};

/*
** Internal ressources management
** Implemenation file : interact_str_ressources.c
*/

t_str_link	*create_str_link(char letter,
		t_str_link *before,
		t_str_link *after);
void		destroy_str_link(t_str_link **link);

#endif
