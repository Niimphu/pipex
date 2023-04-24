# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 19:20:45 by yiwong            #+#    #+#              #
#    Updated: 2023/04/24 17:38:35 by yiwong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc

CFLAGS = -Wall -Wextra -Werror -g

DEPS = lib/pipex.h

LIBFT = libft.a

LIBFTDIR = lib/libft/

PRINTF = ft_printf.a

PRINTFDIR = lib/ft_printf/

SRC = src/main.c \
		src/heredoc.c \
		src/pipex.c \
		src/data.c \
		src/error.c \
		src/free.c \
		src/utils.c \
		lib/get_next_line/get_next_line.c \
		lib/get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

NAME = pipex

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT) $(PRINTF)
		@$(CC) $(CFLAGS) $(OBJ) $(PRINTF) $(LIBFT) -o $(NAME)

%.o: %.c $(DEPS)
		@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
		@$(MAKE) -C $(LIBFTDIR)
		@mv $(LIBFTDIR)$(LIBFT) .

$(PRINTF) :
		@$(MAKE) -C $(PRINTFDIR)
		@mv $(PRINTFDIR)$(PRINTF) .

bonus : all

clean :
		@rm -f $(OBJ) $(LIBFT) $(PRINTF)
		@$(MAKE) clean -C $(LIBFTDIR)
		@$(MAKE) clean -C $(PRINTFDIR)

fclean : clean
		 @rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
