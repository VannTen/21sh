/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive_string_defs.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 09:38:43 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/19 10:22:35 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERACTIVE_STRING_DEFS_H
# define INTERACTIVE_STRING_DEFS_H
# include "interactive_string_interface.h"

typedef struct s_str_link	t_str_link;

struct	s_str_link
{
	struct s_str_link	*before;
	struct s_str_link	*after;
	char				letter;
};

struct	s_interact_str
{
	struct s_str_link	*begin;
	struct s_str_link	*end;
	struct s_str_link	*current;
};

#endif
