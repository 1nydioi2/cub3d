/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_is_data_cub_file_valid.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:30:44 by jutocche          #+#    #+#             */
/*   Updated: 2025/11/01 16:21:12 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_integers_structs_texture_color_and_map(t_cub *cub)
{
	cub->north.present = 0;
	cub->north.line = 0;
	cub->north.index_path = 0;
	cub->south.present = 0;
	cub->south.line = 0;
	cub->south.index_path = 0;
	cub->east.present = 0;
	cub->east.line = 0;
	cub->east.index_path = 0;
	cub->west.present = 0;
	cub->west.line = 0;
	cub->west.index_path = 0;
	cub->floor.present = 0;
	cub->floor.line = 0;
	cub->floor.index_rgb = 0;
	cub->ceiling.present = 0;
	cub->ceiling.line = 0;
	cub->ceiling.index_rgb = 0;
	cub->map.present = 0;
	cub->map.line_start = 0;
	cub->map.line_end = 0;
	cub->map.is_delimited = 0;
	cub->map.height=0;
} 

bool	is_data_cub_file_valid(t_cub *cub)
{
	init_integers_structs_texture_color_and_map(cub);
	if (is_all_elements_presents(cub) == false)
	{
		free_cub_and_close(cub);
		return (false);
	}
	if (is_wall_textures_valid(cub) == false)
	{
		free_cub_and_close(cub);
		return (false);
	}
	if (is_floor_or_ceiling_valid(cub) == false)
	{
		free_cub_and_close(cub);
		return (false);
	}
	if (is_map_valid(cub) == false)
	{
		free_cub_and_close(cub);
		return (false);
	}
	return (true);
}

bool init_mlx(t_cub *cub)
{
	cub->mlx.mlx = mlx_init();
	if (!cub->mlx.mlx)
	{
		ft_printf("Error\nmlx init failed\n");
		return (false);
	}
	return (true);
}
