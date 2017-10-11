/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gram_gen_sym_interface.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 14:11:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/11 14:24:59 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAM_GEN_SYM_INTERFACE_H
# define GRAM_GEN_SYM_INTERFACE_H
# include "gram_gen_prods_interface.h"

typedef struct s_symbol	t_symbol;

/*
** Ressources management
** Implementation file : gram_gen_sym_ressources.c
*/

t_symbol	*create_symbol(void);
void		destroy_symbol(t_symbol **to_destroy);

/*
** Setters
** Implementation file : gramm_gen_sym_set.c
*/

t_prod		*add_prod(t_symbol *sym, t_prod *prod);
t_prod		*take_left_recursive(t_symbol *sym);

/*
** Getters
** Implementation file : gramm_gen_sym_get.c
*/

char const	*get_name(t_symbol const *sym);

/*
** Printers
** Implementation file : gramm_gen_sym_print.c
*/

void		*print_sym(t_symbol const *sym);

/*
** Parsing a prod
** Implementation file : gramm_gen_sym_parse.c
*/

t_sym	*parse_symbol(char const *str_sym);
#endif
