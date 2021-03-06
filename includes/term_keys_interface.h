/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_keys_interface.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 18:28:05 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/27 10:35:25 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_KEYS_INTERFACE_H
# define TERM_KEYS_INTERFACE_H
# include "line_editor_interface.h"
# include "libft.h"
# include <stddef.h>

typedef struct s_key		t_key;
typedef int					(*t_term_action)(t_line_editor*);

/*
** t_key constructor and destructor
** Implementation file : term_key_ressources.c
*/

t_key			*generate_term_keys(void);
void			destroy_term_keys(t_key **sequences);

/*
** Various key readings and compare
** Implementation file : term_keys.c
*/

t_term_action	read_full_key(t_key const *str,
		int fd, char *buf, size_t *index);
t_term_action	get_key_action(t_key const *key);
t_lst			*populate_stack(t_key *sequences, char c);
t_bool			could_be_key(t_key const *key, size_t index, int c);

#endif
