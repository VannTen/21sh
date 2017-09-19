/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_actions_interface.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 11:04:55 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/19 14:25:27 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_ACTIONS_INTERFACE_H
# define TERM_ACTIONS_INTERFACE_H

typedef struct s_line_editor	t_line_editor;
typedef struct s_keypad_cmd		t_keypad_cmd;
typedef int						(*t_term_action)(t_line_editor*);

int				term_act(void);
t_keypad_cmd	*generate_keys_cmd_sequences(void);

#endif
