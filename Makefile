# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 19:20:45 by yiwong            #+#    #+#              #
#    Updated: 2023/03/20 17:45:38 by yiwong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc

CFLAGS = -Wall -Wextra -Werror -g

DEPS = push_swap.h

LIBFT = libft.a

LIBFTDIR = lib/libft/

PRINTF = ft_printf.a

PRINTFDIR = lib/ft_printf/

SRC = src/main.c \
		src/pipex.c

OBJ = $(SRC:.c=.o)

NAME = pipex

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT) $(PRINTF)
		$(CC) $(CFLAGS) $(OBJ) $(PRINTF) $(LIBFT) -o $(NAME)

%.o: %.c $(DEPS)
		$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
		$(MAKE) -C $(LIBFTDIR)
		mv $(LIBFTDIR)$(LIBFT) .

$(PRINTF) :
		$(MAKE) -C $(PRINTFDIR)
		mv $(PRINTFDIR)$(PRINTF) .
		
clean :
		 rm -f $(OBJ)
		$(MAKE) clean -C $(LIBFTDIR)
		$(MAKE) clean -C $(PRINTFDIR)

fclean : clean
		 rm -f $(NAME) $(LIBFT) $(PRINTF)

re : fclean all

.PHONY : all clean fclean re bonus
