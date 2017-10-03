/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_interface.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 12:18:31 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/03 12:50:06 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_INTERFACE_H
# define TOKEN_INTERFACE_H

typedef struct s_token	t_token;

/*
** Token recognition
** Implementation file : token_recognition.c
*/

t_token	*recognize_token(char const **input);
void	destroy_token(t_token **to_destroy);
#endif
