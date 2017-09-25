/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_str_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 19:09:10 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/25 16:32:43 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interactive_string_defs.h"
#include "libft.h"

size_t	forward_x_letter(t_interact_str *str, size_t nb_letter)
{
	size_t	index;

	index = 0;
	while (index < nb_letter && str->current != str->end)
	{
		str->current = str->current->after;
		index++;
	}
	str->index += index;
	return (index);
}

size_t	back_x_letter(t_interact_str *str, size_t nb_letter)
{
	size_t	index;

	index = 0;
	while (index < nb_letter && str->current != str->begin)
	{
		str->current = str->current->before;
		index++;
	}
	str->index -= index;
	return (index);
}

size_t	go_to_first_letter(t_interact_str *str)
{
	size_t	nb_of_move;

	str->current = str->begin;
	nb_of_move = str->index;
	str->index = 0;
	return (nb_of_move);
}

size_t	go_to_last_letter(t_interact_str *str)
{
	size_t	nb_of_move;

	str->current = str->end;
	nb_of_move = str->size - str->index;
	str->index = str->size;
	return (nb_of_move);
}
