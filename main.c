#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	full_img(t_data img)
{
	int x;
	int y;
	int a;
	int b;

	y = 0;
	while (y < 1000)
	{
		x = 0;
		while (x < 1000)
		{
			a = x - 500;
			b = y - 500;
			if (((a*a) + (b*b)) < (500*500))
				my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			x++;
		}
		y++;
	}
}

int	main(void)
{
	t_vars vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 1000, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	full_img(img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}
