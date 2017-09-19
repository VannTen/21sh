/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_key_sequences.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 10:47:09 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/19 14:28:42 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_actions_defs.h"
#include "libft.h"
#include <stdarg.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

# define MAX_SEQ_LENGHT 10

t_bool		is_validated(t_line_editor *buf)
{
	return (get_current_letter(buf->buffer) == '\n');
}

t_lst	*populate_stack(char **sequences, char c)
{
	size_t	index;
	t_lst	*stack;

	index = 0;
	stack = NULL;
	while (sequences[index] != NULL)
	{
		if (sequences[index][0] == c)
			f_lstpush(sequences[index], &stack);
		index++;
	}
	return (stack);
}

static t_bool	match(const void *v_sequence, va_list args)
{
	const t_keypad_cmd	*sequence;

	sequence = v_sequence;
	return (sequence->str[va_arg(args, size_t)] == va_arg(args, int));
}

static size_t	send_to_buffer(char *buf, t_interact_str *buffer)
{
	size_t	index;
	void	*ret;

	index = 0;
	ret = &index;
	while (buf[index] != '\0' && ret != NULL)
	{
		ret = add_letter(buffer, buf[index]);
		buf[index] = '\0';
		index++;
	}
	return (ret != NULL ? index : index - 1);
}

char			consume_one_sequence(t_keypad_cmd *seq, char *buf, size_t index,
		t_line_editor *buffer)
{
	size_t	seq_size;
	char	left_alone;
	int		ret;

	seq_size = ft_strlen(seq->str);
	while (index < seq_size && ft_strequ_short(seq->str, buf))
	{
		ret = read(STDIN_FILENO, buf + index, 1);
		if (ret == -1)
			fatal();
		else if (ret == 0)
			return ('\0');
	}
	if (ft_strequ(seq->str, buf))
	{
		seq->action(buffer);
		left_alone = '\0';
	}
	else
	{
		left_alone = buf[index - 1];
		buf[index - 1] = '\0';
	}
	return (left_alone);
}

char			search_seq(char *buf, t_line_editor *buffer)
{
	t_lst	*possible_match;
	size_t	index;
	int		ret;

	possible_match = populate_stack(buffer->seq_received, buf[0]);
	if (possible_match == NULL)
		return ('\0');
	index = 1;
	while (f_lst_len(possible_match) > 1)
	{
		ret = read(STDIN_FILENO, buf + index, 1);
		index++;
		buf[index] = '\0';
		if (ret == 0)
			return ('\0');
		else
			f_lstremoveif_va(&possible_match, &match, &no_destroy,
					index, buf[index]);
	}
	if (f_lst_len(possible_match) == 1)
		return (consume_one_sequence(f_lstpop(&possible_match), buf, index,
					buffer));
	else
		return ('\0');
}

int	search_for_sequence(int fd, t_line_editor *term)
{
	char	buf[10];
	char	left_alone;

	left_alone = '\0';
	while (!is_validated(term))
	{
		if (left_alone != '\0')
			buf[0] = left_alone;
		else
			read(fd, &buf, 1);
		buf[1] = '\0';
		left_alone = search_seq(buf, term);
		if (ft_strlen(buf) != send_to_buffer(buf, term->buffer))
			fatal();
	}
	return (0);
}