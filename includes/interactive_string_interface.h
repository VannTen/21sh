/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive_string_interface.h                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 09:51:02 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/19 10:23:30 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERACTIVE_STRING_INTERFACE_H
# define INTERACTIVE_STRING_INTERFACE_H

/*
** Forward declaration of the struct
*/

typedef struct s_interact_str	t_interact_str;

/*
** Create, destroy
*/

t_interact_str	*create_interact_str(void);
void			destroy_interact_str(t_interact_str** to_destroy);
t_interact_str	*add_letter(t_interact_str *str, char new_letter);
#endif
