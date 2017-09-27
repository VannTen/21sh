/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_ary_tree_defs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:20:32 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/11 15:22:56 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef N_ARY_TREE_DEFS_H
# define N_ARY_TREE_DEFS_H
# include "libft.h"

struct	s_n_node
{
	char	letter;
	t_lst	*child_node;
};

struct	s_n_tree
{
	t_lst	*first_letter_nodes;
	size_t	max_depth;
};

#endif
