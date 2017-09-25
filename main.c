/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 13:21:43 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/25 10:12:25 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <termcap.h>
#include <unistd.h>
#include <termios.h>
#include "term_actions_interface.h"
#include "libft.h"

char PC;

int	fta_putchar(int c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
int main(void)
{
	char	*term;
	int		success;
	char	*cmd;
	struct termios	tty_original;
	struct termios	tty_settings;
	char	*result;
	char	*pc;

	errno = 0;
	term = getenv("TERM");
	success = tgetent(NULL, term);
	if (success == 1)
	{
		tcgetattr(STDIN_FILENO, &tty_original);
		tcgetattr(STDIN_FILENO, &tty_settings);
		tty_settings.c_lflag &= ~(ICANON | ECHO);
		tty_settings.c_oflag &= ~(OPOST);
		tty_settings.c_cc[VMIN] = 1;
		tty_settings.c_cc[VTIME] = 0;
		tcsetattr(STDIN_FILENO, TCSANOW, &tty_settings);
		pc = tgetstr("pc", NULL);
		if (pc != NULL)
			PC = pc[0];
		else
			PC = '\0';
		cmd = tgetstr("ks", NULL);
		write(STDOUT_FILENO, cmd, ft_strlen(cmd));
		result = term_act();
		cmd = tgetstr("ke", NULL);
		write(STDOUT_FILENO, cmd, ft_strlen(cmd));
		tcsetattr(STDIN_FILENO, TCSANOW, &tty_original);
		ft_printf("\nResult :\n\"%s\"\n", result);
	}
	else
	{
		printf("%d\n%s", success, term);
		perror(NULL);
	}
	return (0);
}
