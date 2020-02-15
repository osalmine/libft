# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/24 14:46:14 by osalmine          #+#    #+#              #
#    Updated: 2020/02/05 12:15:26 by osalmine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SOURCE = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		 ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c \
		 ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c \
		 ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
		 ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
		 ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
		 ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
		 ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
		 ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
		 ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
		 ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c \
		 ft_strtrim.c ft_tolower.c ft_toupper.c ft_isblank.c ft_islower.c \
		 ft_isupper.c ft_words.c ft_nbs.c ft_strchri.c ft_dtoa.c ft_abs.c \
		 ft_itoa_base.c get_next_line.c
OBJ = $(SOURCE:%.c=%.o)
INCLUDE = libft.h
FLAGS = -Wall -Werror -Wextra

PRINTF_DIR = ft_printf/
PRINTF_LIB = libftprintf.a

all: $(NAME)

$(NAME): $(INCLUDE) $(SOURCE)
	@gcc $(FLAGS) -I$(INCLUDE) -c $(SOURCE)
	@make -C $(PRINTF_DIR)
	@cp $(PRINTF_DIR)$(PRINTF_LIB) $(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Compiled $(NAME)"

clean:
	@make -C $(PRINTF_DIR) clean
	@rm -f $(OBJ)
	@echo "Cleaned obj files"

fclean: clean
	@make -C $(PRINTF_DIR) fclean
	@rm -f $(NAME)
	@echo "Cleaned $(NAME)"

re: fclean all
	@make -C $(PRINTF_DIR) re

.PHONY: all clean fclean re
