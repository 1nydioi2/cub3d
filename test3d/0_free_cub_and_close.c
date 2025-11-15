/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_free_cub_and_close.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 14:11:55 by jutocche          #+#    #+#             */
/*   Updated: 2025/11/01 16:21:34 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void cleanup_mlx(t_cub *cub)
{
	if (cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	if (cub->mlx)
	{
		mlx_destroy_display(cub->mlx);
		free(cub->mlx);
		cub->mlx = NULL;
	}
}

void free_cub_map(t_cub *cub)
{
	int i;

	i = 0;
	if (cub->map.map)
	{
		while (i < cub->map.height)
		{
			if (cub->map.map[i])
			{
				free(cub->map.map[i]);
				cub->map.map[i] = NULL;
			}
			i++;
		}
		free(cub->map.map);
	}
}

void free_value_color(t_cub *cub)
{
	if (cub->floor.value_color)
	{
		free(cub->floor.value_color);
		cub->floor.value_color = NULL;
	}
	if (cub->ceiling.value_color)
	{
		free(cub->ceiling.value_color);
		cub->ceiling.value_color = NULL;
	}
}

void free_rgb_color_ceiling(t_cub *cub)
{
	int i;

	i = 0;
	if (cub->ceiling.rgb_color)
	{
		while (i < 3)
		{
			if (cub->ceiling.rgb_color[i])
			{
				free(cub->ceiling.rgb_color[i]);
				cub->ceiling.rgb_color[i] = NULL;
			}
			i++;
		}
		free(cub->ceiling.rgb_color);
	}
}

void free_rgb_color_floor(t_cub *cub)
{
	int i;

	i = 0;
	if (cub->floor.rgb_color)
	{
		while (i < 3)
		{
			if (cub->floor.rgb_color[i])
			{
				free(cub->floor.rgb_color[i]);
				cub->floor.rgb_color[i] = NULL;
			}
			i++;
		}
		free(cub->floor.rgb_color);
	}
}

void free_textures_map(t_cub *cub)
{
	if (cub->north.path_textures)
	{
		free(cub->north.path_textures);
		cub->north.path_textures = NULL;
	}
	if (cub->south.path_textures)
	{
		free(cub->south.path_textures);
		cub->south.path_textures = NULL;
	}
	if (cub->east.path_textures)
	{
		free(cub->east.path_textures);
		cub->east.path_textures = NULL;
	}
	if (cub->west.path_textures)
	{
		free(cub->west.path_textures);
		cub->west.path_textures = NULL;
	}
}

void free_cub_copy(t_cub *cub)
{
	int i;

	i = 0;
	if (cub->file.cub_copy)
	{
		while (i < cub->file.line_count)
		{
			if (cub->file.cub_copy[i])
			{
				free(cub->file.cub_copy[i]);
				cub->file.cub_copy[i] = NULL;
			}
			i++;
		}
		free(cub->file.cub_copy);
	}
}

void free_cub_filename(t_cub *cub)
{
	if (cub->file.filename)
	{
		free(cub->file.filename);
		cub->file.filename = NULL;
	}
}

void free_cub_and_close(t_cub *cub)
{
	if (cub->file.fd >= 0)
		close(cub->file.fd);
	cleanup_mlx(cub);
	free_cub_filename(cub);
	free_cub_copy(cub);
	free_textures_map(cub);
	free_rgb_color_floor(cub);
	free_rgb_color_ceiling(cub);
	free_value_color(cub);
	free_cub_map(cub);







	
}

