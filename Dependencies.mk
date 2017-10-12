#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Dependencies.mk                                    :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/05/10 16:08:11 by mgautier          #+#    #+#             *#
#*   Updated: 2017/10/12 09:49:56 by mgautier         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

# Dependencies

SYSTEM_LIBRARY := termcap
LIBRARY := libft
OBJECTS :=
ELSE :=

# Sub directories

SUBDIRS := grammar_gen

### Additional rules for the grammar generator
%_source.c includes/%_interface.h %_init.c %_names.c:\
	%.grammar grammar_generator
	./$(word 2, $^) $< 
