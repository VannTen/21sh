# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Srcs.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/19 07:58:53 by mgautier          #+#    #+#              #
#*   Updated: 2017/09/30 17:26:55 by mgautier         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

# Define target and sources

TARGET := shell

SRC :=\
	input_tools.c\
	term_device_debug.c\
	term_device_checks.c\
	term_device_init.c\
	term_device_input.c\
	term_device_get.c\
	term_device_actions.c\
	term_string_codes.c\
	term_keys.c\
	term_keys_ressources.c\
	ft_arrow_keys.c\
	functions_keys.c\
	control_keys.c\
	misc_keys.c\
	term_insert_del.c\
	cursor_movement.c\
	interact_str_modif_state.c\
	interact_str_check.c\
	interact_str_get.c\
	interact_str_move.c\
	interact_string.c\
	interact_str_ressources.c\
	line_editor_ressources.c\
	line_editor_checks.c\
	main.c\
	search_key_sequences.c\
	term_actions.c

# Directories

SRC_DIR :=
OBJ_DIR := object
INC_DIR := includes
DEP_DIR := .dep
TEST_DIR := test
