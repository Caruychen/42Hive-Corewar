# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    src.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdavis <jdavis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 16:59:05 by caruychen         #+#    #+#              #
#    Updated: 2022/10/19 11:11:52 by jdavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR := ./src
SRCS := $(SRC_DIR)/main.c
SRCS += $(SRC_DIR)/init.c
SRCS += $(SRC_DIR)/init_flag.c
SRCS += $(SRC_DIR)/init_read.c
SRCS += $(SRC_DIR)/init_input.c
SRCS += $(SRC_DIR)/game_start.c
SRCS += $(SRC_DIR)/update_carriages.c
SRCS += $(SRC_DIR)/check.c
SRCS += $(SRC_DIR)/print.c
SRCS += $(SRC_DIR)/print_core.c
SRCS += $(SRC_DIR)/print_flag.c
SRCS += $(SRC_DIR)/op_one_arg.c
SRCS += $(SRC_DIR)/op_two_arg.c
SRCS += $(SRC_DIR)/op_three_arg.c
SRCS += $(SRC_DIR)/op_fork.c
SRCS += $(SRC_DIR)/op_bit.c
SRCS += $(SRC_DIR)/op_helper.c
SRCS += $(SRC_DIR)/move.c
SRCS += $(SRC_DIR)/read_args_core.c
SRCS += $(SRC_DIR)/error.c
SRCS += $(SRC_DIR)/read_bytes.c
SRCS += $(SRC_DIR)/print_flag_2.c
SRCS += $(SRC_DIR)/pcb.c
SRCS += $(SRC_DIR)/collect_champs.c
SRCS += $(SRC_DIR)/collect.c
