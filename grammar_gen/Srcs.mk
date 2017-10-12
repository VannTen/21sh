# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Srcs.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/19 07:58:53 by mgautier          #+#    #+#              #
#*   Updated: 2017/10/12 15:06:56 by mgautier         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

# Define target and sources

TARGET := grammar_generator

SRC :=\
	gramm_gen_prod_ressources.c\
	gramm_gen_prod_parse.c\
	gramm_gen_prod_test.c\
	gramm_gen_prod_print.c\
	gramm_gen_prod_set.c\
	gramm_gen_prod_get.c\
	gramm_gen_sym_parse.c\
	gramm_gen_sym_print.c\
	gramm_gen_sym_set.c\
	gramm_gen_sym_get.c\
	gramm_gen_sym_ressources.c\
	grammar_parse.c\
	grammar_print_init.c\
	grammar_print_proto.c\
	grammar_print_header.c\
	grammar_print_source.c\
	grammar_transform.c\
	generate_grammar.c

# Directories

SRC_DIR :=
OBJ_DIR := object
INC_DIR := includes
DEP_DIR := .dep
TEST_DIR := test
