# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccharrie <ccharrie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/10 12:16:23 by ccharrie          #+#    #+#              #
#    Updated: 2019/03/04 15:36:17 by lduqueno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re compile

COLOR_GREEN = "\033[1;32;40m"
COLOR_RED = "\033[1;31;40m"
COLOR_YELLOW = "\033[1;33;40m"
COLOR_BLUE = "\033[1;38;5;21m"
COLOR_ORANGE = "\033[1;38;5;202m"
COLOR_GRAY = "\033[1;38;5;244m"
COLOR_RESET = "\033[0m"

NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

HEADER_PATH = includes

SRC_PATH = srcs
SRC_NAME = main.c \
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

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = objs
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

LIBFT_PATH = libft
LIBFT_INCLUDE = -I$(LIBFT_PATH)
LIBFT = -L$(LIBFT_PATH) -lft

LIBFTPRINTF_PATH = libft/ft_printf
LIBFTPRINTF_INCLUDE = -I$(LIBFTPRINTF_PATH)/includes
LIBFTPRINTF = -L$(LIBFTPRINTF_PATH) -lftprintf

all: compile

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) -c -o $@ $(CFLAGS) $< $(LIBFT_INCLUDE) $(LIBFTPRINTF_INCLUDE) -I$(HEADER_PATH)

$(NAME): $(OBJ)
	@echo $(COLOR_YELLOW)"Linking "$@"..."$(COLOR_RESET)
	@echo $(COLOR_GRAY)
	$(CC) $^ $(MLX_FLAGS) $(LIBFTPRINTF) $(LIBFT) -o $@
	@echo $(COLOR_RESET)
	@echo $(COLOR_GREEN)$(NAME)" successfully created."$(COLOR_RESET)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

compile: $(OBJ_PATH)
	@echo $(COLOR_BLUE)"==Entering "$(LIBFT_PATH)"=="$(COLOR_RESET)
	@echo $(COLOR_GRAY)
	@make -C $(LIBFT_PATH)
	@echo $(COLOR_RESET)
	@echo $(COLOR_BLUE)"==Exiting "$(LIBFTPRINTF_PATH)"=="$(COLOR_RESET)
	@echo $(COLOR_BLUE)"==Entering "$(LIBFTPRINTF_PATH)"=="$(COLOR_RESET)
	@echo $(COLOR_GRAY)
	@make -C $(LIBFTPRINTF_PATH)
	@echo $(COLOR_RESET)
	@echo $(COLOR_BLUE)"==Exiting "$(LIBFTPRINTF_PATH)"=="$(COLOR_RESET)
	@echo $(COLOR_YELLOW)"Compiling "$(NAME)"..."$(COLOR_RESET)
	@echo $(COLOR_GRAY)
	@make $(NAME)
	@echo $(COLOR_RESET)

clean:
	@echo $(COLOR_RED)"Removing "$(OBJ_PATH)"..."$(COLOR_RESET)
	rm -Rf $(OBJ_PATH)
	@echo  $(COLOR_BLUE)"==Entering "$(LIBFT_PATH)"=="$(COLOR_RESET)
	@make -C $(LIBFT_PATH) clean
	@echo  $(COLOR_BLUE)"==Exiting "$(LIBFT_PATH)"=="$(COLOR_RESET)
	@echo  $(COLOR_BLUE)"==Entering "$(LIBFTPRINTF_PATH)"=="$(COLOR_RESET)
	@make -C $(LIBFTPRINTF_PATH) clean
	@echo  $(COLOR_BLUE)"==Exiting "$(LIBFTPRINTF_PATH)"=="$(COLOR_RESET)

fclean: clean
	@echo $(COLOR_RED)"Removing "$(NAME)"..."$(COLOR_RESET)
	rm -f $(NAME)
	@echo  $(COLOR_BLUE)"==Entering "$(LIBFT_PATH)"=="$(COLOR_RESET)
	@make -C $(LIBFT_PATH) fclean
	@echo  $(COLOR_BLUE)"==Exiting "$(LIBFT_PATH)"=="$(COLOR_RESET)
	@echo  $(COLOR_BLUE)"==Entering "$(LIBFTPRINTF_PATH)"=="$(COLOR_RESET)
	@make -C $(LIBFTPRINTF_PATH) fclean
	@echo  $(COLOR_ORANGE)"==Exiting "$(LIBFTPRINTF_PATH)"=="$(COLOR_RESET)

re: fclean all
