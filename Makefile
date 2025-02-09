# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/26 22:12:47 by hoskim            #+#    #+#              #
#    Updated: 2025/02/09 04:31:53 by hoskim           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = clang
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes

SRCS_DIR = src
MAIN_DIR = $(SRCS_DIR)/main
OPS_DIR = $(SRCS_DIR)/operations
SORTER_DIR = $(SRCS_DIR)/stack_sorter
STACK_MANAGER_DIR = $(SRCS_DIR)/stack_manager
UTILS_DIR = $(SRCS_DIR)/utils

SRCS = $(MAIN_DIR)/push_swap.c \
		$(OPS_DIR)/push_operations.c \
		$(OPS_DIR)/reverse_operations.c \
		$(OPS_DIR)/rotate_operations.c \
		$(OPS_DIR)/swap_operations.c \
		$(STACK_MANAGER_DIR)/stack_manager.c \
		$(SORTER_DIR)/sort_large.c \
		$(SORTER_DIR)/sort_manager.c \
		$(SORTER_DIR)/sort_small.c \
		$(SORTER_DIR)/sort_utils.c \
		$(UTILS_DIR)/general_utils.c \
		$(UTILS_DIR)/general_utils2.c

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