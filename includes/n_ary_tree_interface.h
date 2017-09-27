/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_ary_tree_interface.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:26:10 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/11 15:29:23 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef N_ARY_TREE_INTERFACE_H
# define N_ARY_TREE_INTERFACE_H

typedef s_n_tree	t_n_tree;

t_n_tree	*create_n_tree(void);
void		*add_n_tree(t_n_tree *tree, void *elem);

#endif
