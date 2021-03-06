/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootaketaishi <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 01:54:38 by ootaketai         #+#    #+#             */
/*   Updated: 2022/03/31 01:54:40 by ootaketai        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_p *p, double cx, double cy)
{
	double	nx;
	double	ny;
	double	ox;
	double	oy;

	nx = 0.0;
	ny = 0.0;
	p->n = 0;
	while (p->n <= p->max_n)
	{
		ox = nx;
		oy = ny;
		nx = ox * ox - oy * oy + cx;
		ny = 2.0 * ox * oy + cy;
		if ((nx * nx + ny * ny) > 4.0)
			return (p->n);
		(p->n)++;
	}
	p->n = -1;
	return (p->n);
}

void	draw_mandelbrot(t_p *p)
{
	double	cx;
	double	cy;
	double	x;
	double	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cx = 1.5 * (x - WIDTH / 2) / (WIDTH * 0.5 * p->zoom) - p->move_x;
			cy = (y - HEIGHT / 2) / (HEIGHT * 0.5 * p->zoom) - p->move_y;
			pixel_put(p, x, y, mandelbrot(p, cx, cy));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
}
