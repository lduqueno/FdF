# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 12:57:51 by ccharrie          #+#    #+#              #
#    Updated: 2018/03/05 18:57:28 by ccharrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
RM = rm -rf
CCFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
LIB = -C $(D_LIB)
OBJS = $(SRCS:.c=.o)
SRCS = error.c parsingconv.c main.c mover.c menu.c tracing.c increaser.c event.c
D_SRCS = ./srcs/
D_LIB = ./libft/
D_INC = ./includes/
MAKEFLAGS = s

.PHONY: all clean fclean re
all: $(NAME)

%.o:$(D_SRCS)%.c
	@$(CC) $(CCFLAGS) -I $(D_LIB) -I $(D_INC) -o $@ -c $<

$(NAME): $(OBJS)
	@make $(LIB)
	@echo "\033[32;1mLibrary compilation done 😏\033[0m"
	@$(CC) $(CCFLAGS) -o $(NAME) $(OBJS) -L $(D_LIB) -lft $(MLXFLAGS)
	@echo "\033[36;1mLibrary compilation done 😃\033[0m"

clean:
	@make clean $(LIB)
	@echo "\033[31;1mClean of objects done 🗑️\033[0m"
	@$(RM) $(OBJS)

fclean: clean
	@make fclean $(LIB)
	@$(RM) $(NAME)
	@echo "\033[31;1mClean of executable done 🗑️\033[0m"

re: fclean all
