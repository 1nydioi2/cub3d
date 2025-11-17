

#include "cub3d.h"

void close_program(t_cub *cub)
{
	free_cub_and_close(cub);
	exit(0);
}

int	close_window(void *param)
{
	t_cub	*close;

	close = (t_cub *)param;
	close_program(close);
	return (0);
}

/*int	key_hook(int keycode, t_cub *cub)
{
	if (keycode == 65307)
		close_program(cub);
	return (0);
}*/

int start_cub(t_cub *cub)
{
	cub->win = mlx_new_window(cub->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (!cub->win)
	{
		cleanup_mlx(cub);
		return (-1);
	}
	// mlx_new_img 
	// mlx get data adr 
	// put img to windows
	init_data(cub);
	refresh_player_pos(cub, 1);
	mlx_hook(cub->win, 2, 1L << 0, key_hook, cub);
	mlx_hook(cub->win, 17, 0, close_window, cub);
	mlx_loop(cub->mlx);
	return (0);
}
