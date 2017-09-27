/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editor_interface.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 11:04:55 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/27 11:37:37 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_EDITOR_INTERFACE_H
# define LINE_EDITOR_INTERFACE_H
# include "libft.h"

typedef struct s_line_editor	t_line_editor;

/*
** Ressources management
** Implementation file : line_editor_ressources.c
*/

t_line_editor	*create_line_editor(int fd);
void			destroy_line_editor(t_line_editor **line_editor);

/*
** Input/output point
** Implementation file : term_actions.c
*/

char			*term_act(void);

/*
** Input processing and searching key sequences
** Implementation file : search_key_sequences.c
*/

int				search_for_sequence(t_line_editor *term);

/*
** Check and validation
** Implementation file : line_editor_checks.c
*/

int				confirm_line(t_line_editor *line_editor);
t_bool			is_validated(t_line_editor const *line_editor);

#endif
