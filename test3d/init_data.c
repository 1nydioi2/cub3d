#include "cub3d.h"

void	init_img(t_cub *cub)
{
	t_data	*data;
	
	data = &cub->data;
	data->img_plr.width = PLR_WIDTH;
	data->img_plr.height = PLR_HEIGHT;
	data->img_eraser.width = PLR_WIDTH;
	data->img_eraser.height = PLR_HEIGHT;
	data->img_wall.width = BCK_WIDTH;
	data->img_wall.height = BCK_HEIGHT;
	data->img_ground.width = BCK_WIDTH;
	data->img_ground.height = BCK_HEIGHT;
	data->img_line.width = LIN_WIDTH;
	data->img_line.height = LIN_HEIGHT;
	data->img_plr.img = mlx_xpm_file_to_image(cub->mlx,
		"images/20px_Player.xpm", &data->img_plr.width, &data->img_plr.height);
	data->img_eraser.img = mlx_xpm_file_to_image(cub->mlx,
		"images/20px_Black.xpm", &data->img_eraser.width, &data->img_eraser.height);
	data->img_wall.img = mlx_xpm_file_to_image(cub->mlx,
		"images/50px_White.xpm", &data->img_wall.width, &data->img_wall.height);
	data->img_ground.img = mlx_xpm_file_to_image(cub->mlx,
		"images/50px_Gray.xpm", &data->img_ground.width, &data->img_ground.height);
	data->img_line.img = mlx_xpm_file_to_image(cub->mlx,
		"images/3px_Line.xpm", &data->img_ground.width, &data->img_ground.height);
}

void	init_data(t_cub *cub)
{

	init_img(cub);
	cub->data.plr.a = 0;
	cub->data.plr.dx = (cos(cub->data.plr.a) * SPEED);
	cub->data.plr.dy = (sin(cub->data.plr.a) * SPEED);
	
}
