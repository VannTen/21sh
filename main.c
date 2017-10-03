/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 13:21:43 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/03 13:15:49 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token_defs.h"
#include "libft.h"
#include <unistd.h>


int main(int argc, const char **argv)
{
	char const	**test;
	char const	*test_1;
	t_token	*token;

	if (argc < 2)
		return (1);

	test_1 = argv[1];
	test = &test_1;
	token = recognize_token(test);
	if (token->type == OPERATOR)
		ft_putstr("Operator : [");
	else
		ft_putstr("Word : [");
	write(STDOUT_FILENO, token->start, token->size);
	ft_putstr("]\n");
	while(**test != '\0')
	{
		destroy_token(&token);
		token = recognize_token(test);
		if (token->type == OPERATOR)
			ft_putstr("Operator : [");
		else
			ft_putstr("Word : [");
		write(STDOUT_FILENO, token->start, token->size);
		ft_putstr("]\n");
	}
	destroy_token(&token);
	return (0);
}
