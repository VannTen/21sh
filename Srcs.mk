# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Srcs.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/19 07:58:53 by mgautier          #+#    #+#              #
#*   Updated: 2017/09/26 12:39:32 by mgautier         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

# Define target and sources

TARGET := shell

SRC :=\
	ft_arrow_keys.c\
	term_device_init.c\
	term_device_get.c\
	term_device_actions.c\
	term_string_codes.c\
	term_keys.c\
	term_keys_ressources.c\
	functions_keys.c\
	term_insert_del.c\
	cursor_movement.c\
	interact_str_get.c\
	interact_str_move.c\
	interact_string.c\
	line_editor.c\
	main.c\
	search_key_sequences.c\
	term_actions.c

# Directories

SRC_DIR :=
OBJ_DIR := object
INC_DIR := includes
DEP_DIR := .dep
TEST_DIR := test
