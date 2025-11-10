#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mlx/mlx.h"

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

	float		player_x;
	float		player_y;
	float		player_dx;
	float		player_dy;
	float		player_angle;

	char	map[MAP_HEIGHT][MAP_WIDTH];
}				t_data;

void	print_ray(t_data *_data, float nx, float ny)
{
	float	dx;
	float	dy;
	int		div;
	int		x;
	int		y;

	dx = (nx - _data->player_x);
	dy = (ny - _data->player_y);
	
	if (dx > dy)
		div = dx / dy;
	else
		div = dy / dx;
	x = ;
	while (x <)
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

void	refresh_player_pos(t_data *_data, int new_x, int new_y)
{
	mlx_put_image_to_window(_data->mlx, _data->win, _data->img_eraser.img, _data->player_x, _data->player_y);
	print_map(_data);
	_data->player_x = new_x;
	_data->player_y = new_y;	
	mlx_put_image_to_window(_data->mlx, _data->win, _data->img_plr.img, _data->player_x, _data->player_y);
}

int	key_hook(int keycode, t_data *_data)
{
	switch (keycode)
	{
		case UP_ARROW :
		{
			refresh_player_pos(_data, _data->player_x, _data->player_y - 5);
			break;
		}
		case LEFT_ARROW :
		{
			_data->player_a -= 0.1;
			if (_data->player_a < 0)
				_data->player_a += (2 * PY);
			_data->player_dx = (cos(pa) * 5);
			_data->player_dy = (sin(pa) * 5);
			refresh_player_pos(_data, _data->player_x - 5, _data->player_y);
			break;
		}
		case DOWN_ARROW :
		{
			refresh_player_pos(_data, _data->player_x + _data->player_dx ,_data->player_y - _data->player_dx);
			break;
		}
		case RIGHT_ARROW :
		{
			_data->player_a += 0.1;
			if (_data->player_a > (2 * PI))
				_data->player_a -= (2 * PY);
			_data->player_dx = (cos(pa) * 5);
			_data->player_dy = (sin(pa) * 5);
			refresh_player_pos(_data, _data->player_x + 5, _data->player_y);
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

	_data.img_plr.img = mlx_xpm_file_to_image(_data.mlx, "images/20px_Player.xpm", &_data.img_plr.width, &_data.img_plr.height);	
	_data.img_eraser.img = mlx_xpm_file_to_image(_data.mlx, "images/20px_Black.xpm", &_data.img_eraser.width, &_data.img_eraser.height);	
	_data.img_wall.img = mlx_xpm_file_to_image(_data.mlx, "images/50px_White.xpm", &_data.img_wall.width, &_data.img_wall.height);	
	_data.img_ground.img = mlx_xpm_file_to_image(_data.mlx, "images/50px_Gray.xpm", &_data.img_ground.width, &_data.img_ground.height);	
	
	cpy_map(&_data);
	print_map(&_data);
	refresh_player_pos(&_data, 225, 225);
	mlx_hook(_data.win, 2, 1L << 0, &key_hook, &_data);
	mlx_loop(_data.mlx);
}
