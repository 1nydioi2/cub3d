#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mlx/mlx.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


int	main()
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	char	*dst;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1320, 630, "Fear");
	img.img = mlx_new_image(mlx, 1320, 630);
	img.addr = mlx_get_data_addr(
		img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	for (int x = 0; x < 1290; x++)
	{
		for (int y = 0; y < 600; y++)
		{
			dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
			*(unsigned int*)dst = 0x00FF0000;
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 15, 15);
	mlx_loop(mlx);
}
