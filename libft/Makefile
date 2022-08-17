# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dyoung <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 20:03:57 by dyoung            #+#    #+#              #
#    Updated: 2020/01/10 15:46:26 by dyoung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAG = -Wall -Wextra -Werror

SRC = *.c

OBJ = *.o

HEAD = *.h

all: $(NAME)

$(NAME):
	gcc $(FLAG) -I $(HEAD) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc -c $(FLAG) $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
