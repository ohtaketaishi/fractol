#include "fractol.h"

int	mouse_hook(int keycode, int x, int y, t_p *p)
{
	(void)x;
	(void)y;
	
	mlx_mouse_get_pos(p->win, &p->mouse_x, &p->mouse_y);
	printf("%d:%d\n", p->mouse_x, p->mouse_y);
	if (keycode == MOUSE_UP)
	{
		p->zoom *= 1.1;
		//p->max_n += 10;
		printf("max_n:%d\n", p->max_n);
	}
	else if (keycode == MOUSE_DOWN)
	{
		p->zoom *= 0.9;
		//p->max_n -= 10;
		if (p->max_n <= 100)
			p->max_n = 100;
		printf("max_n:%d\n", p->max_n);
	}
	draw_fractol(p);

	return (0);
}

int	key_hook(int keycode, t_p *p)
{
	printf("%d\n", keycode);
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(p->mlx, p->win);
		system("leaks fractol");
		exit(EXIT_FAILURE);
	}
	else if (keycode == LEFT_KEY)
		p->move_x += 0.1/p->zoom;
	else if (keycode == RIGHT_KEY)
		p->move_x -= 0.1/p->zoom;
	else if (keycode == UP_KEY)
		p->move_y += 0.1/p->zoom;
	else if (keycode == DOWN_KEY)
		p->move_y -= 0.1/p->zoom;
	else if (keycode == C_KEY)
		p->c++;
	draw_fractol(p);
	return (0);
}

int	close_hook(void)
{
	system("leaks fractol");
	exit(EXIT_FAILURE);
	return (0);
}

