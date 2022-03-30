#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> //printf
# include <math.h> // pow
# include <mlx.h> //mlx...
# include <stdlib.h> //exit



# define WIDTH 800//8004:3
# define HEIGHT 600//600
# define C_KEY 8
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define DOWN_KEY 125
# define UP_KEY 126
# define ESC_KEY 53
# define MOUSE_UP 4
# define MOUSE_DOWN 5
# define MANDELBROT 1
# define JULIA1 2
# define JULIA2 3
# define JULIA3 4
# define BURNINGSHIP 5

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_p{
	void	*mlx;
	void	*win;
	int		mouse_x;
	int		mouse_y;
	double	move_x;
	double	move_y;
	double	cx;
	double	cy;
	int		n;
	int		max_n;
	double	zoom;
	int		fractol;
	int		c;
	t_img	img;
}				t_p;

//hook.c
int	mouse_hook(int keycode, int x, int y, t_p *p);
int	key_hook(int keycode, t_p *p);
int	close_hook(void);

//mandelbrot.c
void	draw_mandelbrot(t_p *p);
int	mandelbrot(t_p *p, double cx, double cy);

//julia.c
void	draw_julia(t_p *p);
int julia(t_p *p, double nx, double ny);

//other
void	init(t_p *p);
void	pixel_put(t_p *p, double x, double y, int n);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		n_to_HSV(int n);
int		ft_strcmp(char *s1, char *s2);
int	check_av(char *av);
void draw_fractol(t_p *p);

//coler
int color(t_p *p);
int	rainbow(t_p *p);
int	black(t_p *p);
int	white(t_p *p);

//burningship
double	ft_abs(double num);
int	burningship(t_p *p, double cx, double cy);
void	draw_burningship(t_p *p);

#endif
