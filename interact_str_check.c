/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_str_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:38:06 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/27 19:06:15 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interactive_string_defs.h"
#include "libft.h"

int	int_str_state_of_quote(t_interact_str const *str)
{
	t_str_link	*current;
	static char	quote_characters[] = {'"', '\'', '\0'};
	t_bool		quote_states[ARRAY_LENGTH(quote_characters) - 1];

	current = str->begin;
	init_bool_array(quote_states, ARRAY_LENGTH(quote_states), FALSE);
	while (current != str->end)
	{
		update_states(quote_states, current->letter, quote_characters);
		current = current->after;
	}
	return (return_result(quote_states, ARRAY_LENGTH(quote_characters) - 1));
}

