/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:19:52 by nilamber          #+#    #+#             */
/*   Updated: 2025/11/12 19:44:53 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mlx/mlx.h"
#include "externals.h"

#define PI 3.14159265

#define UP_ARROW 65362
#define LEFT_ARROW 65361
#define DOWN_ARROW 65364
#define RIGHT_ARROW 65363
#define ESC_KEY 65307

#define MAP_HEIGHT 9
#define MAP_WIDTH 9

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		width;
	int		height;
	int		line_length;
	int		endian;
}				t_img;


typedef struct	s_data
{
	void	*mlx;
	void	*win;
	
	t_img	img_plr;
	t_img	img_eraser;
	t_img	img_wall;
	t_img	img_ground;
	t_img	img_line;

	float		player_x;
	float		player_y;
	float		player_dx;
	float		player_dy;
	float		player_a;

	char	map[MAP_HEIGHT][MAP_WIDTH];
}				t_data;

typedef	struct	s_pos
{
	int	v;
	int	delta;
	int	s;

}		t_pos;

void	set_pos(t_pos *x, t_pos	*y, t_pos **weak, t_pos **strong)
{
	x->s = 1 - (2 * (x->delta < 0));
	x->delta = ft_fabs(x->delta);
	x->v = 0;

	y->s = 1 - (2 * (y->delta < 0));
	y->delta = ft_fabs(y->delta);
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

void	print_line(t_data *_data, float nx, float ny)
{
	t_pos	x;
	t_pos	y;
	t_pos	*weak;
	t_pos	*strong;
	int		div;

	weak = NULL;
	strong = NULL;
	x.delta = nx - _data->player_x;
	y.delta = ny - _data->player_y;
	set_pos(&x, &y, &weak, &strong);
	if (strong->delta == 0 || weak->delta == 0)
		div = strong->delta;
	else
		div = strong->delta / weak->delta;
	while (ft_abs(x.v) < x.delta && ft_abs(y.v) < y.delta)
	{
		if (strong->v > weak->v + div)
			weak->v += weak->s;
		else
			strong->v += strong->s;
		mlx_put_image_to_window(_data->mlx, _data->win, _data->img_line.img,
			_data->player_x + x.v, _data->player_y + y.v);
		printf("x = %d\ty = %d\n", x.v, y.v);
	}
	return ;
}

void	print_map(t_data *_data)
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
			if (_data->map[my][mx] == 1)
			{
				mlx_put_image_to_window(
						_data->mlx, _data->win, _data->img_wall.img, x, y);
			}
			else if (_data->map[my][mx] == 0)
			{
				mlx_put_image_to_window(
						_data->mlx, _data->win, _data->img_ground.img, x, y);

			}	
			mx++;
			x += 52;
		}
		my++;
		y += 52;
	}
}

void	refresh_player_pos(t_data *_data, float new_x, float new_y)
{
	mlx_put_image_to_window(_data->mlx, _data->win, _data->img_eraser.img, _data->player_x, _data->player_y);
	print_map(_data);
	_data->player_x = new_x;
	_data->player_y = new_y;
	mlx_put_image_to_window(_data->mlx, _data->win, _data->img_plr.img, _data->player_x, _data->player_y);
	print_line(_data, _data->player_x + _data->player_dx, _data->player_y + _data->player_dy);
}

int	key_hook(int keycode, t_data *_data)
{
	switch (keycode)
	{
		case UP_ARROW :
		{
			refresh_player_pos(_data, 
				_data->player_x + _data->player_dx,
					_data->player_y + _data->player_dy);
			break;
		}
		case LEFT_ARROW :
		{
			_data->player_a -= 0.1;
			if (_data->player_a < 0)
				_data->player_a += (2 * PI);
			_data->player_dx = (cos(_data->player_a) * 10);
			_data->player_dy = (sin(_data->player_a) * 10);
			refresh_player_pos(_data, _data->player_x, _data->player_y);
			break;
		}
		case DOWN_ARROW :
		{
			refresh_player_pos(_data, 
				_data->player_x - _data->player_dx,
					_data->player_y - _data->player_dy);
			break;
		}
		case RIGHT_ARROW :
		{
			_data->player_a += 0.1;
			if (_data->player_a > (2 * PI))
				_data->player_a -= (2 * PI);
			_data->player_dx = (cos(_data->player_a) * 10);
			_data->player_dy = (sin(_data->player_a) * 10);
			refresh_player_pos(_data, _data->player_x, _data->player_y);
			break;
		}
		case ESC_KEY :
		{
			exit (0);
		}
		default :
			printf("key = %d\n", keycode);
	}
	return (0);
}
		
void	cpy_map(t_data *_data)
{
	int		y;
	int		x;

	char map[MAP_HEIGHT][MAP_WIDTH] =
	{
		{1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1}
	};
	
	y = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_HEIGHT)
		{
			_data->map[y][x] = map[y][x];
			x++;
		}	
		y++;
	}	
}

int	main()
{
	t_data	_data;

	_data.mlx = mlx_init();
	_data.win = mlx_new_window(_data.mlx, 500, 500, "Fear");

	_data.img_plr.width = 20;
	_data.img_plr.height = 20;
	_data.img_eraser.width = 20;
	_data.img_eraser.height = 20;
	_data.img_wall.width = 20;
	_data.img_wall.height = 20;
	_data.img_ground.width = 20;
	_data.img_ground.height = 20;
	_data.img_line.width = 1;
	_data.img_line.height = 1;

	_data.img_plr.img = mlx_xpm_file_to_image(_data.mlx, "images/20px_Player.xpm", &_data.img_plr.width, &_data.img_plr.height);	
	_data.img_eraser.img = mlx_xpm_file_to_image(_data.mlx, "images/20px_Black.xpm", &_data.img_eraser.width, &_data.img_eraser.height);	
	_data.img_wall.img = mlx_xpm_file_to_image(_data.mlx, "images/50px_White.xpm", &_data.img_wall.width, &_data.img_wall.height);	
	_data.img_ground.img = mlx_xpm_file_to_image(_data.mlx, "images/50px_Gray.xpm", &_data.img_ground.width, &_data.img_ground.height);	
	_data.img_line.img = mlx_xpm_file_to_image(_data.mlx, "images/1px_Line.xpm", &_data.img_ground.width, &_data.img_ground.height);	
	
	cpy_map(&_data);
	_data.player_a = 0;
	_data.player_dx = (cos(_data.player_a) * 5);
	_data.player_dy = (sin(_data.player_a) * 5);
	
	print_map(&_data);
	refresh_player_pos(&_data, 225, 225);
	
	mlx_hook(_data.win, 2, 1L << 0, &key_hook, &_data);
	mlx_loop(_data.mlx);
}
