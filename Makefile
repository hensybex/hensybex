# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 19:39:19 by medesmon          #+#    #+#              #
#    Updated: 2019/06/25 19:59:32 by medesmon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a

SRC     = *.c

SRCLIB  = libft/*.c

FLAGS   = -Wall -Wextra -Werror

LIB = ./libft/

OBJ = *.o

all : $(NAME)

$(NAME) :
	gcc $(FLAGS) -I. -c $(SRC) $(SRCLIB)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re%