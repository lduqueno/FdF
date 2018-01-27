# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 12:57:51 by ccharrie          #+#    #+#              #
#    Updated: 2018/01/25 16:24:19 by ccharrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
RM = rm -rf
NAME = fdf
FLAGS = -Wall -Wextra -Werror
MLXF = -lmlx -framework OpenGL -framework AppKit
SRCS = parsingconv.c main.c
OBJS = $(SRCS:.c=.o)
MAKEFLAGS = s

all: $(NAME)

$(NAME): $(OBJ)
		@make -C libft/
		@echo "\033[36;1mLibrary compilation done\033[0m"
		@$(CC) -o $(NAME) $(SRCS) libft/libft.a $(MLXF) $(FLAGS)
		@echo "\033[36;1mProject compilation done\033[0m"

clean :
		@make clean -C libft/
		@$(RM) $(OBJS)

fclean: clean
		@make fclean -C libft/
		@$(RM) $(NAME)
		@echo "\033[31;1mClean done\033[0m"

re : fclean all
