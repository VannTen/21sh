/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gram_gen_prods_interface.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 14:06:36 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/11 14:24:34 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAM_GEN_PRODS_INTERFACE_H
# define GRAM_GEN_PRODS_INTERFACE_H

/*
** A production is one sequence of symbols which can derivate a non-terminal
** symbols
*/

typedef struct s_prod	t_prod;

/*
** Testing prod
** Implementation file : gramm_gen_prod_test.c
*/

t_bool	is_left_recursive(t_prod *prod);

/*
** Setting prod
** Implementation file : gramm_gen_prod_set.c
*/

void	add_to_prod(t_symbol_type type, t_prod **prod);
t_prod	*join_prods(t_prod const *prod_1, t_prod const prod_2);

/*
** Printing prods
** Implemenation file : gramm_gen_prod_print.c
*/

void	print_prod(t_prod const *prod);

/*
** Parsing a prod
** Implementation file : gramm_gen_prod_parse.c
*/

t_prod	*parse_prod(char const *str_prod);

#endif
