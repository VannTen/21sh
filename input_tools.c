/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 17:29:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/26 17:30:48 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools_interface.h"
#include <unistd.h>

t_bool	read_another(int fd, char *buf, size_t *index)
{
	int		ret;

	(*index)++;
	ret = read(fd, buf + *index, 1);
	buf[*index + 1] = '\0';
	if (ret == -1)
		fatal();
	else if (ret == 0)
		return (FALSE);
	return (TRUE);
}
