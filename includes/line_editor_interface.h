/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editor_interface.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 11:04:55 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/27 10:15:25 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_EDITOR_INTERFACE_H
# define LINE_EDITOR_INTERFACE_H

typedef struct s_line_editor	t_line_editor;

/*
** Line editor interface
** Implementation file : line_editor.c
*/

t_line_editor	*create_line_editor(int fd);
void			destroy_line_editor(t_line_editor **line_editor);

/*
** Others
*/

char			*term_act(void);
int				search_for_sequence(t_line_editor *term);

#endif
