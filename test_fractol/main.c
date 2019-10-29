#include <stdio.h>
#include <math.h>
#include "mlx.h"
#include <unistd.h> 

# define HEIGHT			1080
# define WIDTH			1920

typedef struct	s_complex
{
	double	re;
	double	im;
}				t_complex;

t_complex init_complex(double re, double im)
{
	t_complex complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

int	main()
{
	float		min_re;
	float		max_re;
	float		min_im;
	float		max_im;
	float		factor_re;
	float		factor_im;
	float		c_re;
	float		c_im;
	float		x;
	float		y;
	int			max_iteration = 50;
	t_complex	z;
	int			i;
	double		t;
	double		red;
	double		green;
	double		blue;
	void		*mlx_ptr;
	void		*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 2000, 2000, "Lil Peep");

	min_re = -2.0;
	max_re = 2.0;
	min_im = -2.0;
	max_im = min_im + (max_re - min_re) * HEIGHT / WIDTH;

	factor_re = (max_re - min_re) / (WIDTH - 1);
	factor_im = (max_im - min_im) / (HEIGHT - 1);

	max_iteration = 1500;

	
	y = 200;
	while (y < HEIGHT + 200)
	{
		c_im = max_im - y * factor_im;
		x = 0;
		while (x < WIDTH)
		{
			
			c_re = min_re + x * factor_re;
			z = init_complex(c_re, c_im);
			i = 0;
			while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
				&& i < max_iteration)
			{
				z = init_complex(
					pow(z.re, 2.0) - pow(z.im, 2.0) + c_re,
					2.0 * z.re * z.im + c_im);
				i++;
			}
			t = (double)i / (double)max_iteration;
			red = (int)(9 * (1 - t) * pow(t, 3) * 255);
			green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
			blue = (int)(8.5 * pow((1 - t), 3) * t * 255);
			int hex_color = red * pow(16, 2) + green * 16 + blue;
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, hex_color);
			x++;
		}
		y++;
	}
	mlx_loop(mlx_ptr);
	return (0);
}