/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_actions_interface.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 11:04:55 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/23 12:10:45 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_ACTIONS_INTERFACE_H
# define TERM_ACTIONS_INTERFACE_H

typedef struct s_line_editor	t_line_editor;
typedef int						(*t_term_action)(t_line_editor*);

/*
** Line editor interface
** Implementation file : line_editor.c
*/

t_line_editor	*create_line_editor(int fd);
void			destroy_line_editor(t_line_editor**);

/*
** Others
*/

char			*term_act(void);
int				search_for_sequence(t_line_editor *term);

#endif
