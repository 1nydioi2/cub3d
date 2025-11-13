/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_check_wall_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:42:58 by jutocche          #+#    #+#             */
/*   Updated: 2025/11/01 16:01:57 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_east(t_cub *cub, int i, int j)
{
	if (ft_strncmp(cub->file.cub_copy[i] + j, "EA", 2) == 0)
	{
		if (cub->east.present == 0)
		{
			cub->east.present = 1;
			cub->file.total_elements++;
			cub->east.line = i;
			cub->east.index_path = j+2;
			return (1);
		}
		else
		{
			error_number_element("EA");
			return (-1);
		}
	}
	return (0);
}
int check_west(t_cub *cub, int i, int j)
{
	if (ft_strncmp(cub->file.cub_copy[i] + j, "WE", 2) == 0)
	{
		if (cub->west.present == 0)
		{
			cub->west.present = 1;
			cub->file.total_elements++;
			cub->west.line = i;
			cub->west.index_path = j+2;
			return (1);
		}
		else
		{
			error_number_element("WE");
			return (-1);
		}
	}
	return (0);
}

int check_south(t_cub *cub, int i, int j)
{
	if (ft_strncmp(cub->file.cub_copy[i] + j, "SO", 2) == 0)
	{
		if (cub->south.present == 0)
		{
			cub->south.present = 1;
			cub->file.total_elements++;
			cub->south.line = i;
			cub->south.index_path = j+2;
			return (1);
		}
		else
		{
			error_number_element("SO");
			return (-1);
		}
			
	}
	return (0);
}

int check_north(t_cub *cub, int i, int j)
{
	if (ft_strncmp(cub->file.cub_copy[i] + j, "NO", 2) == 0)
	{
		if (cub->north.present == 0)
		{
			cub->north.present = 1;
			cub->file.total_elements++;
			cub->north.line = i;
			cub->north.index_path = j+2;
			return (1);
		}
		else
		{
			error_number_element("NO");
			return (-1);
		}
	}
	return (0);
}

int check_wall_textures(t_cub *cub, int i, int j)
{
	int result;

	result = check_north(cub, i, j);
	if (result != 0)
		return (result);
	result = check_south(cub, i, j);
	if (result != 0)
		return (result);
	result = check_west(cub, i, j);
	if (result != 0)
		return (result);
	result = check_east(cub, i, j);
	if (result != 0)
		return (result);
	return (0);
}
