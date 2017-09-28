/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_str_get.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 13:58:27 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/28 11:21:02 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interactive_string_defs.h"
#include "libft.h"
#include <stddef.h>

char	get_current_letter(t_interact_str const *str)
{
	return (str->current->letter);
}

char	*get_full_string(t_interact_str const *str)
{
	char		*new_str;
	t_str_link	*tmp_letter;
	size_t		index;

	new_str = ft_strnew(str->size);
	if (new_str != NULL)
	{
		tmp_letter = str->begin;
		index = 0;
		while (tmp_letter != str->end)
		{
			new_str[index] = tmp_letter->letter;
			index++;
			tmp_letter = tmp_letter->after;
		}
	}
	return (new_str);
}

size_t	int_str_get_size(t_interact_str const *str)
{
	return (str->size);
}

t_bool	is_valid_line(t_interact_str const *str)
{
	return (str->is_valid_line);
}
