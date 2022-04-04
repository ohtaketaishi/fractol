/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootaketaishi <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 01:43:53 by ootaketai         #+#    #+#             */
/*   Updated: 2022/04/05 06:07:37 by ootaketai        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	pixel_put(t_p *p, double x, double y, int n)
{
	if (n == -1)
		my_mlx_pixel_put(&(p->img), x, y, color(p));
	else
		my_mlx_pixel_put(&(p->img), x, y, color(p));
}

void	init(t_p *p)
{
	p->mlx = mlx_init();
	if (!p->mlx)
		exit(EXIT_FAILURE);
	p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "fractol");
	if (!p->win)
		exit(EXIT_FAILURE);
	p->img.img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	if (!p->img.img)
		exit(EXIT_FAILURE);
	p->img.addr = mlx_get_data_addr(p->img.img,
			&p->img.bits_per_pixel, &p->img.line_length, &p->img.endian);
	p->move_x = 0.0;
	p->move_y = 0.0;
	p->max_n = 100;
	p->zoom = 1.0;
	p->n = 0;
	p->c = 0;
}
