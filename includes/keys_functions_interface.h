/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_functions_interface.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:09:25 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/25 15:31:32 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_FUNCTIONS_INTERFACE_H
# define KEYS_FUNCTIONS_INTERFACE_H
# include "term_actions_interface.h"

/*
** This interface file declares all of the function which are to be used when
** some controls keys are used (function are named after the key name)
*/

/*
** Arrows keys
** Implementation file : ft_arrow_keys.c
*/

int	left_arrow(t_line_editor *term);
int right_arrow(t_line_editor *term);
int up_arrow(t_line_editor *term);
int down_arrow(t_line_editor *term);

/*
** Some others keys
** Implemation file : functions_keys.c
*/

int	backspace(t_line_editor *term);
int	delete(t_line_editor *term);
int	home(t_line_editor *term);
int	end(t_line_editor *term);

#endif
