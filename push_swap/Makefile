# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/27 12:36:50 by noobythetur       #+#    #+#              #
#    Updated: 2019/10/17 17:21:32 by medesmon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CH	= checker

NAME_PS = push_swap

SRC_CH	= stack_funcs.c swap_fucns.c get_next_line.c checker.c push_concrete.c input.c checks.c returns.c swap_funcs_2.c swap_funcs_3.c stack_funcs_2.c rotate_final_funcs.c push_swap_2.c free_smth.c

SRC_PS	= push_concrete.c push_swap.c stack_funcs.c swap_fucns.c main.c input.c checks.c returns.c swap_funcs_2.c swap_funcs_3.c stack_funcs_2.c rotate_final_funcs.c push_swap_2.c free_smth.c

FLAGS	=

OBJ_CH = $(SRC_CH:%.c=%.o)

OBJ_PS = $(SRC_PS:%.c=%.o)

LIB = ./libft/

all: $(NAME_CH) $(NAME_PS)

$(NAME_CH):
	@make -C $(LIB) re
	gcc $(FLAGS) -c $(SRC_CH)
	gcc $(FLAGS) -o $(NAME_CH) $(OBJ_CH) -L$(LIB) -lft

$(NAME_PS):
	gcc $(FLAGS) -c $(SRC_PS)
	gcc $(FLAGS) -o $(NAME_PS) $(OBJ_PS) -L$(LIB) -lft

clean:
	@make -C $(LIB) clean
	rm -rf $(OBJ_CH)
	rm -rf $(OBJ_PS)
	
fclean: clean
	@make -C $(LIB) fclean
	rm -rf $(NAME_CH)
	rm -rf $(NAME_PS)

re: fclean all

.PHONY: all clean fclean re