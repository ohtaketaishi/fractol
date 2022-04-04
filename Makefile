# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otaishi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 07:07:31 by otaishi           #+#    #+#              #
#    Updated: 2022/04/05 07:29:05 by otaishi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS = -Wall -Werror -Wextra

SRCS = main.c hook.c mandelbrot.c julia.c burningship.c color.c utils.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(SRCS)
	cc $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(SRCS) -o $(NAME)

clean :
		@rm -rf $(OBJS)

fclean : clean
		@rm -rf $(NAME)

re :	fclean all

bonus: $(NAME)

.PHONY: all clean fclean re bonus
