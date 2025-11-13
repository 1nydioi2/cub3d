/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   20_is_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:52:03 by jutocche          #+#    #+#             */
/*   Updated: 2025/11/01 16:04:42 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool is_correct_characters_in_map(t_cub *cub)
{
	int i;
	int j;
	
	i = 0;
	while (cub->map.map[i])
	{
		j = 0;
		while (cub->map.map[i][j])
		{
			if (cub->map.map[i][j] != '0' &&
				cub->map.map[i][j] != '1' && 
				cub->map.map[i][j] != ' ' && 
				cub->map.map[i][j] != 'N' && 
				cub->map.map[i][j] != 'S' && 
				cub->map.map[i][j] != 'W' && 
				cub->map.map[i][j] != 'E')
			{
				error_wrong_character(cub->map.map[i][j]);
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool copy_map(t_cub *cub)
{
	int i;

	cub->map.map = malloc(sizeof (char *) * (cub->map.height + 1));
	if (cub->map.map == NULL)
	{
		ft_printf("Error\nmalloc cub->map.map failed\n");
		return (false);
	}
	i = 0;
	while (i < cub->map.height)
	{
		cub->map.map[i] = ft_strdup(cub->file.cub_copy[cub->map.line_start]);
		if (cub->map.map[i] == NULL)
		{
			ft_printf("Error\nmalloc cub->map.map[i] failed\n");
			return (false);
		}
		i++;
		cub->map.line_start++;
	}
	cub->map.map[i] = NULL;
	return (true);
}

bool is_map_valid(t_cub *cub)
{
	if (copy_map(cub) == false)
		return (false);
	if (is_correct_characters_in_map(cub) == false)
		return (false);
	if (is_map_closed(cub) == false)
		return (false);
	if (is_one_player_in_map(cub) == false)
		return (false);
	return (true);
}
