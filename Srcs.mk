# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Srcs.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/19 07:58:53 by mgautier          #+#    #+#              #
#*   Updated: 2017/10/03 12:20:08 by mgautier         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

# Define target and sources

TARGET := shell

SYNTAX_ANALYZER:=\
	token_break_rules_1.c\
	token_break_rules_2.c\
	token_break_tools.c\
	token_recognition.c
SRC :=\
	$(SYNTAX_ANALYZER)\
	input_tools.c\
	ft_arrow_keys.c\
	term_device_init.c\
	term_device_input.c\
	term_device_get.c\
	term_device_actions.c\
	term_string_codes.c\
	term_keys.c\
	term_keys_ressources.c\
	functions_keys.c\
	control_keys.c\
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
