/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_device_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 12:12:41 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/02 10:08:37 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_device_defs.h"
#include "libft.h"
#include <termcap.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

static int		cust_putchar(int c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/*
** Substracting one to the number of column is a workaround for a
** inconvenient trouble : whenever I try to delete a character under the
** cursor while in the column before the last,
** it does not work. I have some ideas why this is the case, but that fix will
** do for the time being.
**
** The idea : the fix for eat-newline-glitch (output carriage return and
** newline) leaves that place in a weird state, that causes that behavior.
*/

int				set_device_size(t_term_device *term)
{
	int	ret;

	ret = ioctl(term->fd, TIOCGWINSZ, &(term->dimensions));
	term->dimensions.ws_col -= 1;
	return (ret);
}

t_term_device	*create_term_device(int fd)
{
	t_term_device	*new;

	new = malloc(sizeof(t_term_device));
	if (new != NULL)
	{
		new->fd = fd;
		new->keys_cmd = generate_term_keys();
		new->seq_send = create_cmd_strings();
		new->flags = create_cap_flags();
		new->putchar = cust_putchar;
		if (set_device_size(new) == -1)
			destroy_term_device(&new);
	}
	return (new);
}

void			destroy_term_device(t_term_device **term)
{
	t_term_device	*to_destroy;

	to_destroy = *term;
	if (to_destroy != NULL)
	{
		to_destroy->fd = 0;
		destroy_term_keys(&to_destroy->keys_cmd);
		destroy_cmd_strings(&to_destroy->seq_send);
		destroy_bool_array(&to_destroy->flags, NB_BOOL_CAP);
		free(to_destroy);
		*term = NULL;
	}
}
