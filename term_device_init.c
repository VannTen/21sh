/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_device_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 12:12:41 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/25 00:09:04 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_device_defs.h"
#include "libft.h"
#include <termcap.h>
#include <stdlib.h>
#include <unistd.h>

static int	cust_putchar(int c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

t_term_device	*create_term_device(int fd)
{
	t_term_device	*new;

	new = malloc(sizeof(t_term_device));
	if (new != NULL)
	{
		new->fd = fd;
		new->keys_cmd = generate_keys_cmd_sequences();
		new->seq_send = create_cmd_strings();
		new->cursor.x = tgetnum("li");
		new->cursor.y = tgetnum("co");
		new->putchar = cust_putchar;
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
		destroy_keys_cmd_sequences(&to_destroy->keys_cmd);
		destroy_cmd_strings(&to_destroy->seq_send);
		to_destroy->cursor.x = 0;
		to_destroy->cursor.y = 0;
		free(to_destroy);
		*term = NULL;
	}
}
