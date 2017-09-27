/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_interface.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 17:30:57 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/26 17:31:45 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_INTERFACE_H
# define TOOLS_INTERFACE_H
# include "libft.h"

/*
** Input tools
** Implementation file : input_tools.c
*/

t_bool	read_another(int fd, char *buf, size_t *index);

#endif
