/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_check_floor_ceiling_and_map.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:43:06 by jutocche          #+#    #+#             */
/*   Updated: 2025/11/01 16:02:28 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_invalid_element(t_cub *cub, int i, int j)
{
	if ((ft_strncmp(cub->file.cub_copy[i] + j, "NO", 2) != 0) &&
		(ft_strncmp(cub->file.cub_copy[i] + j, "SO", 2) != 0) &&
		(ft_strncmp(cub->file.cub_copy[i] + j, "WE", 2) != 0) &&
		(ft_strncmp(cub->file.cub_copy[i] + j, "EA", 2) != 0) &&
		(ft_strncmp(cub->file.cub_copy[i] + j, "F", 1) != 0) &&
		(ft_strncmp(cub->file.cub_copy[i] + j, "C", 1) != 0) &&
		(cub->file.cub_copy[i][j] != '1'))
	{
		if (cub->file.cub_copy[i][j] == '0')
			error_map_unclosed();
		else if (cub->file.cub_copy[i][j] == 'N')
			error_start_position('N');
		else if (cub->file.cub_copy[i][j] == 'S')
			error_start_position('S');
		else if (cub->file.cub_copy[i][j] == 'E')
			error_start_position('E');
		else if (cub->file.cub_copy[i][j] == 'W')
			error_start_position('W');
		else
			error_invalid_element();
		return (-1);
	}	
	return (0);
}

int check_is_map(t_cub *cub, int i, int j)
{
	int difference;
	
	if (ft_strncmp(cub->file.cub_copy[i] + j, "1", 1) == 0)
	{
		if (cub->map.present == 0)
		{
			cub->map.present = 1;
			if (cub->file.total_elements < 6)
			{
				difference = 6 - cub->file.total_elements;
				if (difference == 1)
					ft_printf("Error\nMap start but %d element is missing.\n", difference);
				else if (difference > 1)
					ft_printf("Error\nMap start but %d elements are missing.\n", difference);
				return (-1);
			}
			cub->file.total_elements++;
			cub->map.line_start = i;
		}
		return (1);
	}
	return (0);
}

int check_ceiling(t_cub *cub, int i, int j)
{
	if (ft_strncmp(cub->file.cub_copy[i] + j, "C", 1) == 0)
	{
		if (cub->ceiling.present == 0)
		{
			cub->ceiling.present = 1;
			cub->file.total_elements++;
			cub->ceiling.line = i;
			cub->ceiling.index_rgb = j+1;
			return (1);
		}
		else
		{
			error_number_element("C");
			return (-1);
		}
	}
	return (0);
}
int check_floor(t_cub *cub, int i, int j)
{
	if (ft_strncmp(cub->file.cub_copy[i] + j, "F", 1) == 0)
	{
		if (cub->floor.present == 0)
		{
			cub->floor.present = 1;
			cub->file.total_elements++;
			cub->floor.line = i;
			cub->floor.index_rgb = j+1;
			return (1);
		}
		else
		{
			error_number_element("F");
			return (-1);
		}
	}
	return (0);
}

int check_floor_ceiling_and_map(t_cub *cub, int i, int j)
{
	int result;

	result = check_floor(cub, i, j);
	if (result != 0)
		return (result);
	result = check_ceiling(cub, i, j);
	if (result != 0)
		return (result);
	result = check_is_map(cub, i, j);
	if (result != 0)
		return (result);
	result = is_invalid_element(cub, i, j);
	if (result != 0)
		return (result);
	printf("DEBUG check elements: cas non gere\n"); // debug a supprimer a la fin
	return (0);
}
