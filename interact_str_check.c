/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_str_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:38:06 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/28 11:14:59 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interactive_string_defs.h"
#include "libft.h"

int	int_str_state_of_quote(t_interact_str const *str,
		char const *quote_chars)
{
	t_str_link	*current;
	t_bool		*quote_states;
	int			result;
	size_t		size;

	size = ft_strlen(quote_chars);
	quote_states = create_bool_array(size, FALSE);
	if (quote_states == NULL)
		return (-1);
	current = str->begin;
	while (current != str->end)
	{
		update_states(quote_states, current->letter, quote_chars);
		current = current->after;
	}
	result = return_result(quote_states, size);
	destroy_bool_array(&quote_states, size);
	return (result);
}
