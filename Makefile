# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tyassine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/01 15:35:34 by tyassine          #+#    #+#              #
#    Updated: 2016/07/01 18:18:31 by tyassine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME =	calculs.c\
		mlx.c\
		projection.c\
		main.c\
		mouse.c\
		utils.c\
		draw.c\
		make_point.c\
		move_option.c\
		zoom_option.c\
		parsing.c\

NAME = fdf
CC = gcc
CFLAGS = -Werror -Wextra -Wall
OBJ_NAME = $(SRC_NAME:.c=.o)
FRAMEWORKS = -framework OpenGL -framework AppKit
STCS = libmlx.a libft.a

all: $(NAME)

$(NAME): $(LIB) $(OBJ_NAME)
	@rm -f libft.a
	@echo "Making";
	@echo "    __    ________  ____________";
	@echo "   / /   /  _/ __ )/ ____/_  __/";
	@echo "  / /    / // __  / /_    / /   ";
	@echo " / /____/ // /_/ / __/   / /    ";
	@echo "/_____/___/_____/_/     /_/     ";
	@make re -C libft && cp -f libft/libft.a ./
	@make re -C minilibx_macos && cp -f minilibx_macos/libmlx.a ./
	@echo "                                \n\nMaking";
	@echo " .----------------.  .----------------.  .----------------. ";
	@echo "| .--------------. || .--------------. || .--------------. |";
	@echo "| |  _________   | || |  ________    | || |  _________   | |";
	@echo "| | |_   ___  |  | || | |_   ___  \  | || | |_   ___  |  | |";
	@echo "| |   | |_  \_|  | || |   | |    \ | | || |   | |_  \_|  | |";
	@echo "| |   |  _|      | || |   | |    | | | || |   |  _|      | |";
	@echo "| |  _| |_       | || |  _| |___/  | | || |  _| |_       | |";
	@echo "| | |_____|      | || | |________ /  | || | |_____|      | |";
	@echo "| |              | || |              | || |              | |";
	@echo "| '--------------' || '--------------' || '--------------' |";
	@echo " '----------------'  '----------------'  '----------------' ";
	@$(CC) -o fdf $(OBJ_NAME) $(STCS) $(FRAMEWORKS) 
$(OBJ_NAME):
	@$(CC) $(CFLAGS) -c $(SRC_NAME) -I libft -I minilibx_macos/
clean:
	@rm -f *.o
	@rm -f *.a
	@make fclean -C libft
	@make clean -C minilibx_macos

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
