# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 11:56:41 by lnaidu            #+#    #+#              #
#    Updated: 2023/05/26 13:24:25 by lnaidu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRC = ./main.c ./Parsing/checkmap.c
#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m


OBJS = ${SRC:.c=.o}

.c.o:
	@${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJS)
	@make all -C ./Libft
	@$(CC) $(CFLAGS) ${OBJS} ./Libft/libft.a -o $(NAME)
	@echo "$(GREEN) Computing !$(DEFAULT)"

all : $(NAME)

clean :
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)
	@echo "$(YELLOW) Deleting !$(DEFAULT)"

fclean : clean
	@rm -f ./Cub3d
	@make fclean -C ./Libft

re : fclean all

.PHONY: all clean fclean bonus re


	


