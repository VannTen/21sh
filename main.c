/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 13:21:43 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/19 16:59:46 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <termcap.h>
#include <unistd.h>
#include <termios.h>
#include "term_actions_interface.h"

int main(void)
{
	char	*term;
	int		success;
	char	*cmd;
	struct termios	tty_original;
	struct termios	tty_settings;

	errno = 0;
	term = getenv("TERM");
	success = tgetent(NULL, term);
	if (success == 1)
	{
		cmd = tgetstr("ks", NULL);
		tputs(cmd, 1, putchar);
		tcgetattr(STDIN_FILENO, &tty_original);
		tcgetattr(STDIN_FILENO, &tty_settings);
		tty_settings.c_lflag &= (~ICANON & ~ECHOCTL);
		tty_settings.c_cc[VMIN] = 3;
		tty_settings.c_cc[VTIME] = 20;
		tcsetattr(STDIN_FILENO, TCSANOW, &tty_settings);
		term_act();
		tcsetattr(STDIN_FILENO, TCSANOW, &tty_original);
	}
	else
	{
		printf("%d\n%s", success, term);
		perror(NULL);
	}
	return (0);
}
