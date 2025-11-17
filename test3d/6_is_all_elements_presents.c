/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_is_all_elements_presents.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:39:25 by jutocche          #+#    #+#             */
/*   Updated: 2025/11/17 19:56:19 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_end_of_line(t_cub *cub, int i, int j)
{
	if (cub->file.cub_copy[i][j] != '\0')
	{
		if (cub->map.is_delimited == 1)
		{
			if (cub->file.cub_copy[i][j] == '1' || cub->file.cub_copy[i][j] == '0')
				return (-3);
			else
				return (-4);
		}
		return (0);
	}
	if (cub->file.cub_copy[i][j] == '\0' && cub->map.present == 0)
		return (1);
	if (cub->file.cub_copy[i][j] == '\0' && cub->map.present == 1)
	{
		cub->map.is_delimited = 1;
		if (cub->map.line_end == 0)
			cub->map.line_end = i;
		cub->map.height = cub->map.line_end - cub->map.line_start;
		if (cub->map.height < 3)
			return (-2);
		else
			return (1);
	}
	return (0);	
}

int check_all_elements_utils(t_cub *cub, int i, int j)
{
	while (cub->file.cub_copy[i][j] == ' ')
		j++;
	return (j);
}

int check_all_elements(t_cub *cub, int i, int j, int result)
{
	while (cub->file.cub_copy[i])
	{
		j = 0;
		while (cub->file.cub_copy[i][j])
		{
			j = check_all_elements_utils(cub, i, j);
			result = is_end_of_line(cub, i, j);
			if (result == 1)
				break;
			if (result < 0)
				return (result);
			result = check_wall_textures(cub, i, j);
			if (result < 0)
				return (-1);
			if (result > 0)
				break;
			result = check_floor_ceiling_and_map(cub, i, j);
			if (result < 0)
				return (-1);
			if (result > 0)
				break;
		}
		i++;
	}
	return (1);
}

bool is_all_elements_presents(t_cub *cub)
{
	int i;
	int j;
	int k;
	int result;
	
	i = 0;
	j = 0;
	k = 0;
	result = check_all_elements(cub, i, j, k);
	if (result <= -1)
	{
		if (result == -2)
			printf("Error\nThe map is just %d line of height.\n", cub->map.height);
		else if (result == -3)
			printf("Error\nEmpty line detected in the map\n");
		else if (result == -4)
			printf("Error\nAt least one element is detected after the map\n");
		return (false);
	}	
	if (cub->file.total_elements < 7)
	{
		error_missing_map(cub);
		return (false);
	}
	return (true);
}
