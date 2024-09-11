# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 22:12:21 by pjedrycz          #+#    #+#              #
#    Updated: 2024/09/11 21:22:31 by pjedrycz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/zsh

CC 		= clang
CFLAGS 	= -Wall -Werror -Wextra
NAME 	= push_swap

SRC_PATH = src/
OBJ_PATH = obj/

SRC		= main.c \
		input_check.c input_check_utils.c \
		initialization.c \
		stack.c \
		swap.c push.c rotate.c reverse_rotate.c \
		sort_tiny.c sort.c \
		position.c cost.c do_move.c \
		utils.c
SRCS 	= $(addprefix $(SRC_PATH), $(SRC))
OBJ 	= $(SRC:.c=.o)
OBJS 	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS 	= -I ./includes/

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

run:
	make
	setopt shwordsplit