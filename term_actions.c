/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 10:45:04 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/11 12:27:13 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <termcap.h>
#include "libft.h"

int	term_act(void)
{
	char	*left_arrow;
	char	buf[4];
	int		nb_read;

	left_arrow = tgetstr("kl", NULL);
	buf[0] = '\0';
	while (buf[0] != left_arrow[0])
	{
		nb_read = read(STDIN_FILENO, buf, 3);
		buf[nb_read] = '\0';
		ft_printf("\n%d %s\n", nb_read, buf);
	}
	ft_printf("Left arrow first found !\n");

	return (1);
}
