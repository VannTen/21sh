/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 09:50:12 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/11 10:30:41 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libstd.h>
#include "interactive_string_defs.h"

t_interact_str	*create_interact_str(void)
{
	t_interact_str	*new_str;

	new_str = malloc(sizeof(t_interact_str));
	if (new_str != NULL)
	{
		new_str->begin = NULL;
		new_str->end = NULL;
		new_str->current = NULL;
	}
	return (new_str);
}

static struct s_str_link	*create_str_link(char letter,
		t_str_link const *before,
		t_str_link const *after)
{
	struct s_str_link	*new_letter;

	new_letter = malloc(sizeof(struct s_str_link));
	if (new_letter != NULL)
	{
		new_letter->letter = letter;
		new_letter->before = before;
		new_letter->after = after;
	}
	return (new_letter);
}

static void		destroy_str_link(struct	s_str_link *link)
{
	link->before = NULL;
	link->after = NULL;
	link->letter = '\0';
	free(link);
}

void			destroy_interact_str(t_interact_str **ptr_to_destroy)
{
	t_interact_str		*to_destroy;
	struct s_str_link	*current_letter;
	struct s_str_link	*next_letter;

	if (ptr_to_destroy != NULL)
	{
		to_destroy = *ptr_to_destroy;
		next_letter = to_destroy->begin;
		while (next_letter != NULL)
		{
			current_letter = next_letter;
			next_letter = next_letter->after;
			destroy_str_link(current_letter);
		}
		to_destroy->begin = NULL;
		to_destroy->end = NULL;
		to_destroy->current = NULL;
		free(to_destroy);
		*ptr_to_destroy = NULL;
	}
}
