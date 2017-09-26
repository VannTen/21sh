/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive_string_interface.h                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 09:51:02 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/26 17:56:40 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERACTIVE_STRING_INTERFACE_H
# define INTERACTIVE_STRING_INTERFACE_H
# include "libft.h"

/*
** Forward declaration of the struct
*/

typedef struct s_interact_str	t_interact_str;

/*
** Create, destroy
** Implementation file : interact_str_ressources.c
*/

t_interact_str	*create_interact_str(void);
void			destroy_interact_str(t_interact_str** to_destroy);

/*
** Add and delete letter to the string
** Implementation file : interact_string.c
*/

t_interact_str	*add_letter(t_interact_str *str, char new_letter);
t_bool			del_letter(t_interact_str *str);

/*
** Moving inside the string.
** These functions always report how many characters they have moved inside the
** string (which could be less than required if they encounters the begin or the
** end of the string.
** Implementation file : interact_str_move.c
*/

size_t			forward_x_letter(t_interact_str *str, size_t nb_letter);
size_t			back_x_letter(t_interact_str *str, size_t nb_letter);
size_t			go_to_first_letter(t_interact_str *str);
size_t			go_to_last_letter(t_interact_str *str);

/*
** Getters
** Implementation file : interact_str_get.c
*/

char			get_current_letter(t_interact_str const * str);
char			*get_full_string(t_interact_str const * str);
size_t			int_str_get_size(t_interact_str const * str);

#endif
