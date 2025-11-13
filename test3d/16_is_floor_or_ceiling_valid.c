/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   16_is_floor_or_ceiling_valid.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:52:01 by jutocche          #+#    #+#             */
/*   Updated: 2025/11/01 16:04:31 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool is_rgb_settings_ceiling_valid(t_cub *cub)
{
	int ceiling;

	ceiling = split_and_atoi_rgb_ceiling(cub);
	if (ceiling < 0)
	{
		if (ceiling == -1)
			error_number_colors("Ceiling (C)");
		else if (ceiling == -3)
			error_setting_color_empty("Ceiling (C)");
		else if (ceiling == -4)
			error_unreadable_color("Ceiling (C)");
		else if (ceiling == -5)
			error_color_out_of_range("Ceiling (C)");	
		return (false);
	}
	return (true);
}

bool is_rgb_ceiling_exist(t_cub *cub)
{
	while (cub->file.cub_copy[cub->ceiling.line][cub->ceiling.index_rgb] == ' '
		&& cub->file.cub_copy[cub->ceiling.line][cub->ceiling.index_rgb] != '\0')
		cub->ceiling.index_rgb++;
	if (cub->file.cub_copy[cub->ceiling.line][cub->ceiling.index_rgb] == '\0')
	{
		error_setting_color_empty("Ceiling (C)");
		return (false);
	}
	return (true);
}

bool is_rgb_settings_floor_valid(t_cub *cub)
{
	int floor;

	floor = split_and_atoi_rgb_floor(cub);
	if (floor < 0)
	{
		if (floor == -1)
			error_number_colors("Floor (F)");
		else if (floor == -3)
			error_setting_color_empty("Floor (F)");
		else if (floor == -4)
			error_unreadable_color("Floor (F)");
		else if (floor == -5)
			error_color_out_of_range("Floor (F)");
		return (false);
	}
	return (true);
}

bool is_rgb_floor_exist(t_cub *cub)
{
	while (cub->file.cub_copy[cub->floor.line][cub->floor.index_rgb] == ' '
		&& cub->file.cub_copy[cub->floor.line][cub->floor.index_rgb] != '\0')
		cub->floor.index_rgb++;
	if (cub->file.cub_copy[cub->floor.line][cub->floor.index_rgb] == '\0')
	{
		error_setting_color_empty("Floor (F)");
		return (false);
	}
	return (true);
}

bool is_floor_or_ceiling_valid(t_cub *cub)
{
	if (is_rgb_floor_exist(cub) == false || is_rgb_settings_floor_valid(cub) == false)
		return (false);
	if (is_rgb_ceiling_exist(cub) == false || is_rgb_settings_ceiling_valid(cub) == false)
		return (false);
	return (true);
}
