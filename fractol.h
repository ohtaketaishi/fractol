/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootaketaishi <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 02:00:28 by ootaketai         #+#    #+#             */
/*   Updated: 2022/04/05 04:40:36 by ootaketai        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> //printf
# include <unistd.h> //write
# include <math.h> // pow
# include <mlx.h> //mlx...
# include <stdlib.h> //exit EXIT_SUCCESS..

# define WIDTH 800//8004:3
# define HEIGHT 600//600
# define C_KEY 8
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define DOWN_KEY 125
# define UP_KEY 126
# define ESC_KEY 53
# define H_KEY 4
# define J_KEY 38
# define K_KEY 40
# define L_KEY 37
# define MOUSE_UP 4
# define MOUSE_DOWN 5
# define MANDELBROT 1
# define JULIA1 2
# define JULIA2 3
# define JULIA3 4
# define BURNINGSHIP 5

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_p{
	void	*mlx;
	void	*win;
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

//main
void	draw_fractol(t_p *p);
void	chose_fractol(t_p *p, char *av);
int		check_av(char *av);
void	error_phrase(void);

//utils.c
int		ft_strcmp(char *s1, char *s2);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	pixel_put(t_p *p, double x, double y, int n);
void	init(t_p *p);

//hook.c
int		mouse_hook(int keycode, int x, int y, t_p *p);
int		key_hook(int keycode, t_p *p);
int		close_hook(t_p *p);
void	julia_change(int keycode, t_p *p);

//coler
int		color(t_p *p);
int		rainbow(t_p *p);
int		black(t_p *p);
int		white(t_p *p);

//mandelbrot.c
int		mandelbrot(t_p *p, double cx, double cy);
void	draw_mandelbrot(t_p *p);

//julia.c
void	chose_julia(t_p *p, char *av);
int		julia(t_p *p, double nx, double ny);
void	draw_julia(t_p *p);

//burningship
double	ft_abs(double num);
int		burningship(t_p *p, double cx, double cy);
void	draw_burningship(t_p *p);

#endif
