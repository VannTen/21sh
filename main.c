/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 13:21:43 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/27 18:46:35 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <termcap.h>
#include <unistd.h>
#include <termios.h>
#include "line_editor_interface.h"
#include "libft.h"

char PC;

char	*test()
{
	static char	buf[10];

	read(STDIN_FILENO, &buf, 1);
	buf[1] = '\0';
	ft_printf("%d\n%s", (int)buf[0], tgetstr("kb", NULL));
	ft_printf("%d\n%s : %zu\n", (int)buf[0], tgetstr("kb", NULL),
			ft_strlen(tgetstr("kb", NULL)));
	return (buf);
}
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
		tty_settings.c_lflag &=
			~(ICANON | ECHO | IEXTEN);
		tty_settings.c_iflag &=
			~(BRKINT | INPCK | ISTRIP | IXON);
		tty_settings.c_oflag &= ~(OPOST);
		tty_settings.c_cflag &= ~(CSIZE | PARENB);
		tty_settings.c_cflag |= CS8;
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
		//result = test();
		cmd = tgetstr("ke", NULL);
		write(STDOUT_FILENO, cmd, ft_strlen(cmd));
		tcsetattr(STDIN_FILENO, TCSANOW, &tty_original);
		ft_printf("\nResult :\n[[[%s]]]\n%d", result,
				state_of_quote(result, "\"'"));

	}
	else
	{
		printf("%d\n%s", success, term);
		perror(NULL);
	}
	return (0);
}
