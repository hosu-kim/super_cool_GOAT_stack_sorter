# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/26 22:12:47 by hoskim            #+#    #+#              #
#    Updated: 2025/03/04 18:58:32 by hoskim           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = clang
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(shell pwd)/includes

SRCS_DIR = src
MAIN_DIR = $(SRCS_DIR)/main
OPS_DIR = $(SRCS_DIR)/operations
STACK_MANAGER_DIR = $(SRCS_DIR)/stack_manager
STACK_SORTER_DIR = $(SRCS_DIR)/stack_sorter
ALGORITHMS_DIR = $(STACK_SORTER_DIR)/algorithms
STACK_SORTER_UTILS_DIR = $(STACK_SORTER_DIR)/stack_sorter_utils
UTILS_DIR = $(SRCS_DIR)/utils

SRCS = $(MAIN_DIR)/push_swap.c \
		$(OPS_DIR)/push.c \
		$(OPS_DIR)/reverse.c \
		$(OPS_DIR)/rotate.c \
		$(OPS_DIR)/swap.c \
		$(STACK_MANAGER_DIR)/stack_manager.c \
		$(STACK_SORTER_DIR)/stack_sorter.c \
		$(ALGORITHMS_DIR)/sort_large.c \
		$(ALGORITHMS_DIR)/sort_small.c \
		$(STACK_SORTER_UTILS_DIR)/stack_move_utils.c \
		$(STACK_SORTER_UTILS_DIR)/stack_position_utils.c \
		$(STACK_SORTER_UTILS_DIR)/stack_normalize_utils.c \
		$(STACK_SORTER_UTILS_DIR)/stack_range_utils.c \
		$(UTILS_DIR)/general_utils.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re