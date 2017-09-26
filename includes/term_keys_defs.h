/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_keys_defs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 18:26:13 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/26 10:00:09 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_KEYS_DEFS_H
# define TERM_KEYS_DEFS_H
# include "term_keys_interface.h"
# include "keys_functions_interface.h"

struct	s_key
{
	char			*str;
	t_term_action	action;
};

# define KEY_CODES_INIT\
		"kl",\
		"kr",\
		"ku",\
		"kd",\
		"kb",\
		"kD",\
		"kh",\
		"@7"
# define KEY_ACTIONS_INIT\
		left_arrow,\
		right_arrow,\
		up_arrow,\
		down_arrow,\
		backspace,\
		delete,\
		home,\
		end
#endif
