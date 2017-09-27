/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_str_modif_state.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:39:20 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/27 11:44:23 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interactive_string_defs.h"
#include "libft.h"

int	validate_line(t_interact_str *str)
{
	str->is_valid_line = TRUE;
	return (0);
}
