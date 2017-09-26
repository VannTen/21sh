/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 09:50:12 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/26 17:57:11 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interactive_string_defs.h"
#include "libft.h"

t_interact_str	*add_letter(t_interact_str *str, char new_letter)
{
	t_str_link	*new_link;

	new_link = create_str_link(new_letter, str->current->before, str->current);
	if (new_link == NULL)
		return (NULL);
	if (str->current == str->begin)
		str->begin = new_link;
	else
		str->current->before->after = new_link;
	str->current->before = new_link;
	str->size++;
	str->index++;
	return (str);
}

t_bool			del_letter(t_interact_str *str)
{
	t_str_link	*tmp;

	if (str->current == str->end)
		return (FALSE);
	if (str->current == str->begin)
		str->begin = str->current->after;
	str->current->after->before = str->current->before;
	if (str->current->before != NULL)
		str->current->before->after = str->current->after;
	tmp = str->current;
	str->current = str->current->after;
	destroy_str_link(&tmp);
	str->size--;
	return (TRUE);
}
