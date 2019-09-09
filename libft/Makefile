# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: medesmon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/25 23:47:23 by medesmon          #+#    #+#              #
#    Updated: 2019/02/06 05:56:58 by medesmon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Werror -Wextra
FILES = ft_atoi.c ft_lstnew.c ft_strcat.c ft_strncpy.c ft_bzero.c \
		ft_memalloc.c ft_strchr.c ft_strnequ.c ft_capitalize.c ft_memccpy.c \
   		ft_strclr.c ft_strnew.c ft_count_num.c ft_memchr.c ft_strcmp.c \
  		ft_strnstr.c ft_countwords.c ft_memcmp.c ft_strcpy.c ft_strrchr.c \
		ft_get_word_len.c ft_memcpy.c ft_strdel.c ft_strrev.c ft_isalnum.c \
   		ft_memdel.c ft_strdup.c ft_strsplit.c ft_isalpha.c ft_memmove.c \
   		ft_strequ.c ft_strstr.c ft_isascii.c ft_memset.c ft_striter.c \
   		ft_strsub.c ft_isdigit.c ft_putchar.c ft_striteri.c ft_strtrim.c \
		ft_isprint.c ft_putchar_fd.c ft_strjoin.c ft_tolower.c \
		ft_itoa.c ft_putendl.c ft_strlcat.c ft_toupper.c ft_lstadd.c \
	   	ft_putendl_fd.c ft_strlen.c ft_lstdel.c ft_putnbr.c ft_strmap.c \
		ft_lstdelone.c ft_putnbr_fd.c ft_strmapi.c ft_strncmp.c \
		ft_putstr_fd.c ft_lstmap.c ft_lstiter.c ft_putstr.c ft_strncat.c \
		ft_strclen.c ft_strdel1join.c
OBJ = ft_atoi.o ft_lstnew.o ft_strcat.o ft_strncpy.o ft_bzero.o \
	  ft_memalloc.o ft_strchr.o ft_strnequ.o ft_capitalize.o ft_memccpy.o \
	  ft_strclr.o ft_strnew.o ft_count_num.o ft_memchr.o ft_strcmp.o \
	  ft_strnstr.o ft_countwords.o ft_memcmp.o ft_strcpy.o ft_strrchr.o \
	  ft_get_word_len.o ft_memcpy.o ft_strdel.o ft_strrev.o ft_isalnum.o \
	  ft_memdel.o ft_strdup.o ft_strsplit.o ft_isalpha.o ft_memmove.o \
	  ft_strequ.o ft_strstr.o ft_isascii.o ft_memset.o ft_striter.o \
	  ft_strsub.o ft_isdigit.o ft_putchar.o ft_striteri.o ft_strtrim.o \
	  ft_isprint.o ft_putchar_fd.o ft_strjoin.o ft_tolower.o \
	  ft_itoa.o ft_putendl.o ft_strlcat.o ft_toupper.o ft_lstadd.o \
	  ft_putendl_fd.o ft_strlen.o ft_lstdel.o ft_putnbr.o ft_strmap.o \
	  ft_lstdelone.o ft_putnbr_fd.o ft_strmapi.o ft_strncmp.o \
	  ft_putstr_fd.o ft_lstmap.o ft_lstiter.o ft_putstr.o ft_strncat.o \
	  ft_strclen.o ft_strdel1join.o
RM = rm -f
all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) -c $(FILES)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
