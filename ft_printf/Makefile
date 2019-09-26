# **************************************************************************** #
#																			  #
#														 :::	  ::::::::	#
#	Makefile										   :+:	  :+:	:+:	#
#													 +:+ +:+		 +:+	  #
#	By: medesmon <medesmon@student.42.fr>		  +#+  +:+	   +#+		 #
#												 +#+#+#+#+#+   +#+			#
#	Created: 2019/06/25 19:39:19 by medesmon		  #+#	#+#			  #
#	Updated: 2019/06/25 19:59:32 by medesmon		 ###   ########.fr		#
#																			  #
# **************************************************************************** #

CC = gcc
NAME	= libftprintf.a
LIBFTNAME = libft.a

SRC	 = apply.c \
apply_2.c \
ft_printf.c \
letter_c.c \
letter_d_i.c \
letter_f.c \
letter_o.c \
letter_p.c \
letter_s.c \
letter_u.c \
letter_x.c \
letter_x_upper.c \
mods.c \
parser.c \
parser_2.c 

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

OBJ_DIR = ./objfiles

SRCLIB  = libft/*.c

FLAGS   = -Wall -Wextra -Werror

INCLUDES =  -I . -I libft/

LIB = ./libft/

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIB)
	cp $(LIB)$(LIBFTNAME) ./$(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	make clean -C $(LIB)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIB)
	rm -f $(NAME)

re: fclean all

$(OBJ_DIR)/%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJ): |$(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

.PHONY: all clean fclean re%