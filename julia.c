/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootaketaishi <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 01:56:12 by ootaketai         #+#    #+#             */
/*   Updated: 2022/03/31 01:56:14 by ootaketai        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	chose_julia(t_p *p, char *av)
{
	if (!ft_strcmp(av, "julia1"))
	{
		p->fractol = JULIA1;
		p->cx = -0.7;
		p->cy = -0.27015;
	}
	else if (!ft_strcmp(av, "julia2"))
	{
		p->fractol = JULIA2;
		p->cx = -0.3842;
		p->cy = -0.70176;
	}
	else if (!ft_strcmp(av, "julia3"))
	{
		p->fractol = JULIA3;
		p->cx = 0.4;
		p->cy = 0.325;
	}
}

int	julia(t_p *p, double nx, double ny)
{
	double	ox;
	double	oy;

	p->n = 0;
	while (p->n <= p->max_n)
	{
		ox = nx;
		oy = ny;
		nx = ox * ox - oy * oy + p->cx;
		ny = 2 * ox * oy + p->cy;
		if ((nx * nx + ny * ny) > 4)
			return (p->n);
		p->n++;
	}
	return (-1);
}

void	draw_julia(t_p *p)
{
	double	nx;
	double	ny;
	double	x;
	double	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			nx = 1.5 * (x - WIDTH / 2) / (WIDTH * 0.5 * p->zoom) - p->move_x;
			ny = (y - HEIGHT / 2) / (HEIGHT * 0.5 * p->zoom) - p->move_y;
			pixel_put(p, x, y, julia(p, nx, ny));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
}
