# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 19:28:14 by yiwong            #+#    #+#              #
#    Updated: 2023/01/27 19:28:14 by yiwong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

AR = ar rcs

DEPS = ft_print.h

SRC = $(wildcard *.c)

OBJ = ${SRC:.c=.o}

NAME = ft_printf.a

all : $(NAME)

$(NAME) : $(OBJ)
		@ $(CC) $(CFLAGS) -c $(SRC)
		@ $(AR) $(NAME) $(OBJ)

%.o: %.c
		@ $(CC) $(CFLAGS) -c $< -o $@
clean :
		@ rm -f $(OBJ)

fclean : clean
		@ rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re