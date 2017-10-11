# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Srcs.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/19 07:58:53 by mgautier          #+#    #+#              #
#*   Updated: 2017/10/11 19:40:15 by mgautier         ###   ########.fr       *#
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


SRC\ :=\
	$(SRC)\
	gen_grammar_source.c\
	gen_grammar_init.c\
	gen_grammar_names.c\
	init_symbols.c\
	symbol_print.c

### Additional rules for the grammar generator
%_source.c includes/%_interface.h %_init.c %_names.c: %.grammar gram_gen
	./$(word 2, $^) $< 

GEN_GRAMMAR_SRC := generate_header_grammar.c\
	generate_source_grammar.c\
	generate_symbols.c\
	generate_grammar_init.c\
	generate_grammar_names.c\
	gramm_gen_prod_parse.c\
	gramm_gen_prod_test.c\
	gramm_gen_prod_print.c\
	gramm_gen_sym_parse.c\
	gramm_gen_sym_print.c\
	gramm_gen_sym_set.c\
	gramm_gen_sym_get.c\
	gramm_gen_sym_ressources.c\
	generate_grammar.c

GEN_GRAMMAR_OBJ := $(patsubst %.c,object/%.o,$(GEN_GRAMMAR_SRC))

gram_gen: $(GEN_GRAMMAR_OBJ) -lft
	$(CC) -o $@ $^ $(DEBUG_FLAGS) 
$(GEN_GRAMMAR_OBJ): object/%.o: %.c .dep/%.dep | object/ .dep/
	$(if $(PRINT_INFO),$(info Compiling $@))
	$(COMPILE) -iquoteincludes -iquotelibft
	$(POSTCOMPILE)
	$(RM) $(word 2,$^).tmp
	$(TOUCH) $@

# Directories

SRC_DIR :=
OBJ_DIR := object
INC_DIR := includes
DEP_DIR := .dep
TEST_DIR := test
