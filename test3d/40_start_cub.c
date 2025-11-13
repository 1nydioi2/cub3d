

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

int	key_hook(int keycode, t_cub *cub)
{
	if (keycode == 65307)
		close_program(cub);
	return (0);
}

int start_cub(t_cub *cub)
{
	cub->mlx.mlx_win = mlx_new_window(cub->mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (!cub->mlx.mlx_win)
	{
		cleanup_mlx(cub);
		return (-1);
	}
	// mlx_new_img 
	// mlx get data adr 
	// put img to windows
	// use a bool with key press and key release to avoid toggle being annoyong
	mlx_key_hook(cub->mlx.mlx_win, key_hook, cub);
	mlx_hook(cub->mlx.mlx_win, 17, 0, close_window, cub);
	mlx_loop(cub->mlx.mlx);
	return (0);
}
