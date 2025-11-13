/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_is_wall_textures_valid.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:48:49 by jutocche          #+#    #+#             */
/*   Updated: 2025/11/01 15:35:40 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool is_wall_textures_valid(t_cub *cub)
{
	if (textures_north_valid(cub) == false || verify_textures_with_mlx(cub, cub->north.path_textures, "NO") == false)
		return (false);
	if (textures_south_valid(cub) == false || verify_textures_with_mlx(cub, cub->south.path_textures, "SO") == false)
		return (false);
	if (textures_west_valid(cub) == false || verify_textures_with_mlx(cub, cub->west.path_textures, "WE") == false)
		return (false);
	if (textures_east_valid(cub) == false || verify_textures_with_mlx(cub, cub->east.path_textures, "EA") == false)
		return (false);
	return (true);
}
