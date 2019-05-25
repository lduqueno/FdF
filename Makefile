# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlegan <rlegan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/13 16:35:11 by rlegan            #+#    #+#              #
#    Updated: 2019/05/25 19:31:38 by lduqueno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra -O2

NAME = fdf

HEADER = includes

MINILIBX_DIR = minilibx

MLX_FLAGS = -L $(MINILIBX_DIR) -l mlx -framework OpenGL -framework AppKit

LIBFTPRINTF_PATH = libft/ft_printf
LIBFTPRINTF_INCLUDE = $(LIBFTPRINTF_PATH)/includes
LIBFTPRINTF = -L$(LIBFTPRINTF_PATH)

SRC_DIR = srcs

SRC_FILES = main.c \
		parsing.c \
		file.c \
		get_res.c \
		menu.c \
		event.c \
		header.c \
		input.c \
		event_catch.c \
		draw.c \
		coord.c\
		rotate.c \
		color.c \
		help.c \
		reset.c

LIBFT_DIR = libft

OBJS_DIR = objs
OBJS_FILES = $(SRC_FILES:.c=.o)
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS_FILES))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@echo "\n\033[0;33mCompiling final project.. \033[0;32mSuccess!\033m\017"
	$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(LIBFTPRINTF_PATH)/libftprintf.a $(LIBFT_DIR)/libft.a $(MINILIBX_DIR)/libmlx.a $(OBJS)
	@echo "\033[0;31m------------- [ \033[0;36mEVERYTHING IS OK \033[0;31m] -----------\033m\017\033[0m"

$(OBJS_DIR):
	@echo "\033[0;31m------ [ \033[0;35m$(NAME) by lduqueno and ccharrie \033[0;31m] ------"
	@echo "\033[0;33mLinking MLX..\033[0m"
	@make -C $(MINILIBX_DIR) 2> /dev/null
	@echo "\033[0;33mLinking Libft..\033[0m"
	@make -C $(LIBFT_DIR)
	@make -C $(LIBFTPRINTF_PATH)
	@echo "\033[0;32mSuccess!\n\033[0m"
	@mkdir $(OBJS_DIR)

$(OBJS_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(HEADER) -I $(LIBFTPRINTF_INCLUDE) -I $(LIBFT_DIR) -I $(MINILIBX_DIR)
	@echo "\033[0;33mCompiling $<.. \033[0;32mSuccess!\033m\017"

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MINILIBX_DIR) clean
	@make -C $(LIBFTPRINTF_PATH) clean

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(LIBFTPRINTF_PATH) fclean
	@rm -f $(NAME)

re: fclean all
