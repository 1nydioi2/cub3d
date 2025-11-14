/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:19:52 by nilamber          #+#    #+#             */
/*   Updated: 2025/11/14 11:10:04 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "externals.h"

void	set_pos(t_pos *x, t_pos	*y, t_pos **weak, t_pos **strong)
{
	x->s = 1 - (2 * (x->delta < 0));
	x->delta = ft_abs(x->delta);
	x->v = 0;

	y->s = 1 - (2 * (y->delta < 0));
	y->delta = ft_abs(y->delta);
	y->v = 0;

	if (x->delta < y->delta)
	{
		*strong = y;
		*weak = x;
	}
		else
	{
		*strong = x;
		*weak = y;
	}

	return ;
}

void	print_line(t_data *data, float nx, float ny)
{
	t_pos	x;
	t_pos	y;
	t_pos	*weak;
	t_pos	*strong;
	int		div;

	weak = NULL;
	strong = NULL;
	x.delta = nx - data->player_x;
	y.delta = ny - data->player_y;
	set_pos(&x, &y, &weak, &strong);
	if (strong->delta == 0 || weak->delta == 0)
		div = strong->delta;
	else
		div = strong->delta / weak->delta;
//	printf("div = %d\tpx = %f\tpy = %f\tpa = %f\n",div, data->player_x, data->player_y, data->player_a);
//	printf("x = %d\ty = %d\txd = %d, yd = %d\tnx = %f, ny = %f\n",
//			x.v, y.v, x.delta, y.delta, nx, ny);
	while (ft_abs(x.v) + ft_abs(y.v) < x.delta + y.delta)
	{
		if (ft_abs(strong->v) > ft_abs(weak->v) * div)
			weak->v += weak->s;
		else
			strong->v += strong->s;
		mlx_put_image_to_window(data->mlx, data->win, data->img_line.img,
			data->player_x + x.v + OFFSET, data->player_y + y.v + OFFSET);
//		printf("x = %d\ty = %d\n", x.v, y.v);
	}
//	printf("-------------------------------------------------\n");
	return ;
}

void	print_map(t_cub *cub)
{
	int	mx;
	int	my;
	int	x;
	int	y;

	y = 5;
	my = 0;
	while(my < MAP_HEIGHT)
	{
		mx = 0;
		x = 5;
		while(mx < MAP_WIDTH)
		{
			if (cub->map.map[my][mx] == 1)
				mlx_put_image_to_window(
						data->mlx, data->win, data->img_wall.img, x, y);
			else if (cub->map.map[my][mx] == 0)
				mlx_put_image_to_window(
						data->mlx, data->win, data->img_ground.img, x, y);
			mx++;
			x += 52;
		}
		my++;
		y += 52;
	}
}

void	refresh_player_pos(t_cub *cub, int sign)
{
	mlx_put_image_to_window(data->mlx, data->win,
			data->img_eraser.img, data->player_x, data->player_y);
	print_map(cub);
	cub->data.player_x += (cub->data.player_dx * sign);
	cub->data.player_y += (cub->data.player_dy * sign);
	print_line(cub->data, 
		cub->data.player_x + (cub->data.player_dx * 1.1),
		cub->data.player_y + (cub->data.player_dy * 1.1));
	mlx_put_image_to_window(data->mlx, data->win,
			data->img_plr.img, data->player_x, data->player_y);
}

int	key_hook(int keycode, t_cub *cub)
{
	if (keycode == KEY_UP || keycode == KEY_W)
		refresh_player_pos(cub, -1); 
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		refresh_player_pos(cub, 1); 
	else if (keycode == KEY_LEFT || keycode == KEY_A) 
	{
		cub->data.player_a -= 0.1;
		if (cub->data.player_a < 0)
			cub->data.player_a += (2 * PI);
		cub->data.player_dx = (cos(cub->data.player_a) * SPEED);
		cub->data.player_dy = (sin(cub->data.player_a) * SPEED);
		refresh_player_pos(cub);
	}
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
	{
		cub->data.player_a += 0.1;
		if (cub->data.player_a > (2 * PI))
			cub->data.player_a -= (2 * PI);
		cub->data.player_dx = (cos(cub->data.player_a) * SPEED);
		cub->data.player_dy = (sin(cub->data.player_a) * SPEED);
		refresh_player_pos(data, cub->data.player_x, cub->data.player_y);
	}
	else if (keycode == KEY_ESC)
	return (0);
}
		
void	initdata(t_cub *cub)
{

	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub->mlx, 500, 500, "Fear");

	cub->data.img_plr.width = PLR_WIDTH;
	cub->data.img_plr.height = PLR_HEIGHT;
	cub->data.img_eraser.width = PLR_WIDTH;
	cub->data.img_eraser.height = PLR_HEIGHT;
	cub->data.img_wall.width = BCK_WIDHT;
	cub->data.img_wall.height = BCK_HEIGHT;
	cub->data.img_ground.width = BCK_WIDTH;
	cub->data.img_ground.height = BCK_HEIGHT;
	cub->data.img_line.width = LIN_WIDTH;
	cub->data.img_line.height = LIN_HEIGHT;

	cub->data.img_plr.img = mlx_xpm_file_to_image(cub->mlx, "images/20px_Player.xpm", &cub->data.img_plr.width, &cub->data.img_plr.height);	
	cub->data.img_eraser.img = mlx_xpm_file_to_image(cub->mlx, "images/20px_Black.xpm", &cub->data.img_eraser.width, &cub->data.img_eraser.height);	
	cub->data.img_wall.img = mlx_xpm_file_to_image(cub->mlx, "images/50px_White.xpm", &cub->data.img_wall.width, &cub->data.img_wall.height);	
	cub->data.img_ground.img = mlx_xpm_file_to_image(cub->mlx, "images/50px_Gray.xpm", &cub->data.img_ground.width, &cub->data.img_ground.height);	
	cub->data.img_line.img = mlx_xpm_file_to_image(cub->mlx, "images/3px_Line.xpm", &cub->data.img_ground.width, &cub->data.img_ground.height);	
	
	cub->data.player_a = 0;
	cub->data.player_dx = (cos(cub->data.player_a) * SPEED);
	cub->data.player_dy = (sin(cub->data.player_a) * SPEED);
	
	print_map(cub);
	refresh_player_pos(cub, 225, 225);
	
	mlx_hook(cub->win, 2, 1L << 0, &key_hook, cub);
	mlx_loop(cub->mlx);
}
