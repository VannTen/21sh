/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 10:45:04 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/19 13:55:37 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_actions_defs.h"
#include "libft.h"
#include <termcap.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

int	term_act(void)
{
	char	*left_arrow;
	char	buf[4];
	int		nb_read;
	static t_keypad_cmd	*key_sequences = NULL;

	if (key_sequences == NULL)
		key_sequences = generate_keys_cmd_sequences();
		return (1);
}
