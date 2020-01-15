# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/27 12:36:50 by noobythetur       #+#    #+#              #
#    Updated: 2020/01/15 14:46:39 by medesmon         ###   ########.fr        #
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
				to_asm_code \
				file \

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
