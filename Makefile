# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 19:20:45 by yiwong            #+#    #+#              #
#    Updated: 2023/03/18 16:17:39 by yiwong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc

CFLAGS = -Wall -Wextra -Werror -g

DEPS = push_swap.h

SRC = src/main.c \
		src/pipex.c

OBJ = $(SRC:.c=.o)

NAME = pipex

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(DEPS)
		$(CC) $(CFLAGS) -c $< -o $@

clean :
		 rm -f $(OBJ)

fclean : clean
		 rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
