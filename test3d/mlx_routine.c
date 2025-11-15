/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:19:52 by nilamber          #+#    #+#             */
/*   Updated: 2025/11/14 11:10:04 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	print_line(t_cub *cub, t_data *data, float nx, float ny)
{
	t_pos	x;
	t_pos	y;
	t_pos	*weak;
	t_pos	*strong;
	int		div;

	weak = NULL;
	strong = NULL;
	x.delta = nx - data->plr.x;
	y.delta = ny - data->plr.y;
	set_pos(&x, &y, &weak, &strong);
	if (strong->delta == 0 || weak->delta == 0)
		div = strong->delta;
	else
		div = strong->delta / weak->delta;
//	printf("div = %d\tpx = %f\tpy = %f\tpa = %f\n",div, data->plr.x, data->plr.y, data->plr.a);
//	printf("x = %d\ty = %d\txd = %d, yd = %d\tnx = %f, ny = %f\n",
//			x.v, y.v, x.delta, y.delta, nx, ny);
	while (ft_abs(x.v) + ft_abs(y.v) < x.delta + y.delta)
	{
		if (ft_abs(strong->v) > ft_abs(weak->v) * div)
			weak->v += weak->s;
		else
			strong->v += strong->s;
		mlx_put_image_to_window(cub->mlx, cub->win, data->img_line.img,
			data->plr.x + x.v + OFFSET, data->plr.y + y.v + OFFSET);
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
	while(my < cub->map.height)
	{
		mx = 0;
		x = 5;
		while(cub->map.map[my][mx])
		{
			if (cub->map.map[my][mx] == 1)
				mlx_put_image_to_window(
						cub->mlx, cub->win, cub->data.img_wall.img, x, y);
			else if (cub->map.map[my][mx] == 0)
				mlx_put_image_to_window(
						cub->mlx, cub->win, cub->data.img_ground.img, x, y);
			mx++;
			x += 52;
		}
		my++;
		y += 52;
	}
}

void	refresh_player_pos(t_cub *cub, int sign)
{
	mlx_put_image_to_window(cub->mlx, cub->win,
			cub->data.img_eraser.img, cub->data.plr.x, cub->data.plr.y);
	print_map(cub);
	cub->data.plr.x += (cub->data.plr.dx * sign);
	cub->data.plr.y += (cub->data.plr.dy * sign);
	print_line(cub, &cub->data, 
		cub->data.plr.x + (cub->data.plr.dx * 1.1),
		cub->data.plr.y + (cub->data.plr.dy * 1.1));
	mlx_put_image_to_window(cub->mlx, cub->win,
			cub->data.img_plr.img, cub->data.plr.x, cub->data.plr.y);
}

int	key_hook(int keycode, t_cub *cub)
{
	if (keycode == KEY_UP || keycode == KEY_W)
		refresh_player_pos(cub, -1); 
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		refresh_player_pos(cub, 1); 
	else if (keycode == KEY_LEFT || keycode == KEY_A) 
	{
		cub->data.plr.a -= 0.1;
		if (cub->data.plr.a < 0)
			cub->data.plr.a += (2 * PI);
		cub->data.plr.dx = (cos(cub->data.plr.a) * SPEED);
		cub->data.plr.dy = (sin(cub->data.plr.a) * SPEED);
		refresh_player_pos(cub, 1);
	}
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
	{
		cub->data.plr.a += 0.1;
		if (cub->data.plr.a > (2 * PI))
			cub->data.plr.a -= (2 * PI);
		cub->data.plr.dx = (cos(cub->data.plr.a) * SPEED);
		cub->data.plr.dy = (sin(cub->data.plr.a) * SPEED);
		refresh_player_pos(cub, 1);
	}
	else if (keycode == KEY_ESC)
		free_cub_and_close(cub);
	return (0);
}
