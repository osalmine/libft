# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/18 12:39:52 by osalmine          #+#    #+#              #
#    Updated: 2020/02/05 12:20:33 by osalmine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a
FLAGS =		-Wall -Werror -Wextra
INCLUDE =	ft_printf.h
SOURCE =	ft_printf.c parse.c put_csp.c ft_len_put.c put_di.c \
			put_prosent.c put_o.c put_u.c put_x.c put_empty.c put_f.c \
			put_b.c put_a.c
OBJ =		$(SOURCE:%.c=%.o)

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -I$(INCLUDE) -c $(SOURCE)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Compiled $(NAME)"

clean:
	@rm -f $(OBJ)
	@echo Cleaned

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
