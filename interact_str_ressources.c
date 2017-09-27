/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_str_ressources.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 17:52:06 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/27 11:01:16 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interactive_string_defs.h"
#include <stdlib.h>

t_str_link		*create_str_link(char letter,
		t_str_link *before,
		t_str_link *after)
{
	t_str_link	*new_letter;

	new_letter = malloc(sizeof(t_str_link));
	if (new_letter != NULL)
	{
		new_letter->letter = letter;
		new_letter->before = before;
		new_letter->after = after;
	}
	return (new_letter);
}

void			destroy_str_link(t_str_link **link)
{
	t_str_link	*to_destroy;

	to_destroy = *link;
	to_destroy->before = NULL;
	to_destroy->after = NULL;
	to_destroy->letter = '\0';
	free(to_destroy);
	*link = NULL;
}

t_interact_str	*create_interact_str(void)
{
	t_interact_str	*new_str;

	new_str = malloc(sizeof(t_interact_str));
	if (new_str != NULL)
	{
		new_str->begin = create_str_link('\0', NULL, NULL);
		new_str->end = new_str->begin;
		new_str->current = new_str->begin;
		new_str->size = 0;
		new_str->index = 0;
	}
	return (new_str);
}

void			destroy_interact_str(t_interact_str **ptr_to_destroy)
{
	t_interact_str	*to_destroy;
	t_str_link		*current_letter;
	t_str_link		*next_letter;

	if (ptr_to_destroy != NULL)
	{
		to_destroy = *ptr_to_destroy;
		next_letter = to_destroy->begin;
		while (next_letter != NULL)
		{
			current_letter = next_letter;
			next_letter = next_letter->after;
			destroy_str_link(&current_letter);
		}
		to_destroy->begin = NULL;
		to_destroy->end = NULL;
		to_destroy->current = NULL;
		to_destroy->size = 0;
		to_destroy->index = 0;
		free(to_destroy);
		*ptr_to_destroy = NULL;
	}
}
