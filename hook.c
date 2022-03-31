/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootaketaishi <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 01:49:05 by ootaketai         #+#    #+#             */
/*   Updated: 2022/03/31 03:08:59 by ootaketai        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int keycode, int x, int y, t_p *p)
{
	(void)x;
	(void)y;
	if (keycode == MOUSE_UP)
	{
		p->zoom *= 1.1;
		p->max_n += 10;
	}
	else if (keycode == MOUSE_DOWN)
	{
		p->zoom *= 0.9;
		p->max_n -= 10;
		if (p->max_n <= 100)
			p->max_n = 100;
	}
	draw_fractol(p);
	return (0);
}

int	key_hook(int keycode, t_p *p)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(p->mlx, p->win);
		//system("leaks fractol");
		exit(EXIT_FAILURE);
	}
	else if (keycode == LEFT_KEY)
		p->move_x += 0.1 / p->zoom;
	else if (keycode == RIGHT_KEY)
		p->move_x -= 0.1 / p->zoom;
	else if (keycode == UP_KEY)
		p->move_y += 0.1 / p->zoom;
	else if (keycode == DOWN_KEY)
		p->move_y -= 0.1 / p->zoom;
	else if (keycode == C_KEY)
		p->c++;
	julia_change(keycode, p);
	draw_fractol(p);
	return (0);
}

int	close_hook(void)
{
	//system("leaks fractol");
	exit(EXIT_FAILURE);
	return (0);
}

void	julia_change(int keycode, t_p *p)
{
	if (keycode == H_KEY)
		p->cx += 0.01;
	else if (keycode == J_KEY)
		p->cy -= 0.01;
	else if (keycode == K_KEY)
		p->cy += 0.01;
	else if (keycode == L_KEY)
		p->cx -= 0.01;
}
