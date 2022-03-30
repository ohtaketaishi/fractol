NAME = fractol

CFLAGS = -Wall -Werror -Wextra -fsanitize=address

SRCS = main.c hook.c mandelbrot.c julia.c burningship.c color.c utils.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(SRCS)
		cc $(CFLAGS) -I minilibx_opengl_20191021 -L minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit $(SRCS) -o $(NAME)

clean :
		@rm -rf $(OBJS)

fclean : clean
		@rm -rf $(NAME)

re :	fclean all
