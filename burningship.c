#include "fractol.h"

double	ft_abs(double num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

int	burningship(t_p *p, double cx, double cy)
{
	double	nx;
	double	ny;
	double	ox;
	double	oy;

	nx = 0.0;
	ny = 0.0;
	nx = 0.0;
	ny = 0.0;
	p->n = 0;
	while (p->n <= p->max_n)
	{
		ox = ft_abs(nx);
		oy = ft_abs(ny);
		nx = ox * ox - oy * oy + cx;
		ny = ft_abs(2.0 * ox * oy) + cy;
		if ((nx * nx + ny * ny) > 4.0)
			return (p->n);
		(p->n)++;
	}
	p->n = -1;
	return (p->n);
}

void	draw_burningship(t_p *p)
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
			cx = 1.5 * (x - WIDTH / 2) / (WIDTH * 0.3 *p->zoom) - p->move_x;
			cy = (y - HEIGHT / 2) / (HEIGHT * 0.3 * p->zoom) - p->move_y;
			pixel_put(p, x, y, burningship(p, cx, cy));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
}
