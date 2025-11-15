

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
	// use a bool with key press and key release to avoid toggle being annoyong
	init_data(cub);
	refresh_player_pos(cub, 1);
	mlx_hook(cub->win, 2, 1L << 0, &key_hook, cub);
	mlx_hook(cub->win, 17, 0, close_window, cub);
	mlx_loop(cub->mlx);	
	return (0);
}
