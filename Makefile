# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dstepane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/13 20:08:15 by dstepane          #+#    #+#              #
#    Updated: 2018/12/13 20:08:19 by dstepane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEAD = ./fillit.h
SRC = main.c validate.c super_map.c tetri_lists.c solve.c place_on_map.c
OBJS = $(SRC:.c=.o)
LIBFT = libft/libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(LIBFT):
	@make -C libft
	@echo "\033[32mLibft compiled.\033[0m"

$(OBJS):
	$(CC) $(FLAGS) -c $(SRC)
	@echo "\033[32mFillit object files compiled.\033[0m"

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -I $(HEAD) $(LIBFT) -o $(NAME)
	@echo "\033[32mFillit executable compiled.\033[0m"

clean:
	rm -f $(OBJS)
	@echo "\033[31mFillit object files removed.\033[0m"
	@make clean -C libft

fclean: clean
	rm -f $(NAME) $(LIBFT)
	@echo "\033[31mFillit executable and libft.a removed.\033[0m"

re: fclean all
