# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dyoung <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/28 18:21:15 by dyoung            #+#    #+#              #
#    Updated: 2020/02/06 08:21:26 by dyoung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FRAEMWORKS = -framework OpenGL -framework AppKit

FLAGS = -Werror -Wextra -Wall

SRC = ex01/bon.c ex01/bon2.c ex01/check_map.c ex01/fdf_one.c \
	  ex01/read_file.c ex01/start.c ex01/top.c ex01/xryak.c

INCLUDES = libft/libft.a minilibx_macos/libmlx.a

all: $(NAME)

$(NAME):
	@make -C libft/ all
	@make -C minilibx_macos/ all
	gcc -o $(NAME) $(SRC) $(FLAGS) $(INCLUDES) $(FRAEMWORKS)

clean:
	@make -C libft/ clean
	@make -C minilibx_macos/ clean

fclean: clean
	rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
