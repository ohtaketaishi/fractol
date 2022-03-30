#include "fractol.h"

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int		n_to_HSV(int n)
{
	int r;
	int g;
	int b;
	
	r = n%10;
	g = n%10 * 16;
	b = n%10 * 8;
	r = r << 16;
	g = g << 8;

	return (r + g + b);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	pixel_put(t_p *p, double x, double y, int n)
{
	if(n == -1)
		my_mlx_pixel_put(&(p->img), x, y, color(p));
	else
		my_mlx_pixel_put(&(p->img), x, y, color(p));
		//my_mlx_pixel_put(&(p->img), x, y, n * pow(16, 3) + 0x00000000);
}

void	init(t_p *p)
{
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "fractl");
	p->img.img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	p->img.addr = mlx_get_data_addr(p->img.img, &p->img.bits_per_pixel, &p->img.line_length, &p->img.endian);
	p->n = 0;
	p->max_n = 100;
	p->zoom = 1.0;
	p->c = 0;
}

void chose_julia(t_p *p, char *av)
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

void draw_fractol(t_p *p)
{
	if (p->fractol == MANDELBROT)
		draw_mandelbrot(p);
	else if (JULIA1 <= p->fractol && p->fractol <= JULIA3)
		draw_julia(p);
	else if (p->fractol == BURNINGSHIP)
		draw_burningship(p);
}
void	chose_fractol(t_p *p, char *av)
{
	if (!ft_strcmp("mandelbrot", av))
	{
		p->fractol = MANDELBROT;
		p->move_x = 0.5;
		p->move_y = 0.0;
	}
	else if(!ft_strcmp("julia1", av) || !ft_strcmp("julia2", av) || !ft_strcmp("julia3", av))
	{
		chose_julia(p, av);
		p->move_x = 0.0;
		p->move_y = 0.0;
	}
	else if(!ft_strcmp("burningship", av))
		p->fractol = BURNINGSHIP;
	draw_fractol(p);
}

int	check_av(char *av)
{
	if(!ft_strcmp(av, "mandelbrot") || !ft_strcmp(av, "julia1") || !ft_strcmp(av, "julia2") || !ft_strcmp(av, "julia3") || !ft_strcmp(av, "burningship"))
		return (0);
	else
		return (1);
}

int	main(int ac, char **av)
{
	t_p p;

	if (ac != 2 || check_av(av[1]))
		return (1);
	init(&p);
	chose_fractol(&p, av[1]);
	mlx_hook(p.win, 2, 1L<<0, key_hook, &p);
	mlx_hook(p.win, 4, 1L<<0, mouse_hook, &p);
	mlx_hook(p.win, 17, 0, close_hook, &p);
	mlx_loop(p.mlx);
	system("leaks fractol");
	return (0);
}
