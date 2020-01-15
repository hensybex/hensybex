# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timofeykamenetskiy <timofeykamenetskiy@    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/27 12:36:50 by noobythetur       #+#    #+#              #
#    Updated: 2020/01/14 15:42:14 by timofeykame      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			asm

INC =			-I ./includes \
				-I ./ft_printf
LIB =			-L ./ft_printf -lftprintf

FLAGS =

LIST =			asm \
                error \
				parser \
				command_search \
				label_search \
				label_processing \
				label_converter \

OBJ =			$(addprefix obj/, $(addsuffix .o, $(LIST)))

all: $(NAME)

obj/%.o: src/%.c
	@gcc $(FLAGS) -c $< -o $@ $(INC)

$(NAME): obj $(OBJ)
	@make -C ft_printf
	@gcc $(OBJ) -o $(NAME) $(LIB)

obj:
	@mkdir obj

clean:
	@make -C ft_printf clean
	@rm -rf obj
	
fclean: clean
	@make -C ft_printf fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
