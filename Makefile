# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/26 22:12:47 by hoskim            #+#    #+#              #
#    Updated: 2025/01/31 23:14:02 by hoskim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes

SRCS_DIR = srcs
MAIN_DIR = $(SRCS_DIR)/main
OPS_DIR = $(SRCS_DIR)/operations
STACK_DIR = $(SRCS_DIR)/stack_manager
UTILS_DIR = $(SRCS_DIR)/utils

SRCS = $(MAIN_DIR)/push_swap.c \
		$(OPS_DIR)/push_operations.c \
		$(OPS_DIR)/reverse_operations.c \
		$(OPS_DIR)/rotate_operations.c \
		$(OPS_DIR)/swap_operations.c	\
		$(STACK_DIR)/stack_manager.c	\
		$(UTILS_DIR)/stack_sorter_utils.c \
		$(UTILS_DIR)/stack_sorter.c \
		$(UTILS_DIR)/utils.c

%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re