/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 10:45:04 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/15 15:20:56 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <termcap.h>
#include <stdlib.h>
#include "libft.h"

static char	**generate_keys_sequences(void)
{
	static char *key_codes[] = {
		"kl",
		"kr",
		"ku",
		"kd",
		NULL
	};
	static char	*key_sequences[sizeof(key_codes)];
	size_t		index;

	index = 0;
	while (key_codes[index] != NULL)
	{
		key_sequences[index] = tgetstr(key_codes[index], NULL);
		index++;
	}
	key_sequences[index] = NULL;

	return (key_sequences);
}

check_sequences(char **seq, size_t buf_length, char *buf)
{
	size_t	index;
	t_bool	no_match;

	index = 0;
	match = FALSE;
	while (seq[index] != NULL)
	{
		if (strnequ(seq[index], buf, buf_length))
		{
			match = TRUE;
			if (buf_length == strlen(seq[index]))

		}
	}

			}
int	search_for_sequence(int fd, char **sequences)
{
	static char buf[10] = {0};
	size_t		index;
	size_t		buf_index;

	index = 0;
	buf_index = 0;
	while (1)
	{
		read(fd, buf + buf_index, 1);
		check_sequences(sequences, buf_index, buf);
	}
}

int	term_act(void)
{
	char	*left_arrow;
	char	buf[4];
	int		nb_read;
	static char	**key_sequences = NULL;

	if (key_sequences == NULL)
		key_sequences = generate_keys_sequences();
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
