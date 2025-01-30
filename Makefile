# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/26 22:12:47 by hoskim            #+#    #+#              #
#    Updated: 2025/01/30 20:22:25 by hoskim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes

SRCS_DIR = srcs
MAIN_DIR = $(SRCS_DIR)/main
OPS_DIR = $(SRCS_DIR)/OPERATIONS
STACK_DIR = $(SRCS_DIR)/stack
UTILS_DIR = $(SRCS_DIR)/utils

SRCS = $(MAIN_DIR)/push_swap.c \
	   $(OPS_DIR)/operations_reverse.c \
	   $(OPS_DIR)/operation_rotate.c \
	   $(OPS_DIR)/operation_push.c \
	   $(OPS_DIR)/operation_swap.c \
	   $(STACK_DIR)/stack.c \
	   $(UTILS_DIR)/utils.c \
	   $(UTILS_DIR)/sort.c

%.o: %.c
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