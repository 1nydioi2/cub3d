/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21_is_map_closed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:38:53 by jutocche          #+#    #+#             */
/*   Updated: 2025/11/01 16:04:54 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool is_one_player_in_map(t_cub *cub)
{
	int i;
	int j;
	int count_player;
	
	i = 0;
	count_player = 0;
	while (cub->map.map[i])
	{
		j = 0;
		while (cub->map.map[i][j])
		{
			if (cub->map.map[i][j] == 'N' || cub->map.map[i][j] == 'S'
				|| cub->map.map[i][j] == 'W' || cub->map.map[i][j] == 'E')
				count_player++;
			j++;
		}
		i++;
	}
	if (count_player != 1)
	{
		error_count_player(count_player);
		return (false);
	}
	return (true);
}

bool is_character(char c)
{
	if (c == 'N' || c == 'S' || 
		c == 'W' || c == 'E')
		return (true);
	return (false);
}

bool check_space(t_cub *cub, int i, int j)
{
	if (j+1 >= cub->file.line_len || !cub->map.map[i][j+1] || cub->map.map[i][j+1] == ' ')
		return (true);
	if (j-1 < 0 || !cub->map.map[i][j-1] || cub->map.map[i][j-1] == ' ')
		return (true);
	if (i+1 >= cub->map.height || !cub->map.map[i+1][j] || cub->map.map[i+1][j] == ' ')
		return (true);
	if (i-1 < 0 || !cub->map.map[i-1][j] || cub->map.map[i-1][j] == ' ')
		return (true);

	return (false);
}

bool is_map_closed(t_cub *cub)
{
	int i;
	int j;
	
	i = 0;
	while (cub->map.map[i])
	{
		j = 0;
		while (cub->map.map[i][j])
		{
			if (cub->map.map[i][j] == '0' && check_space(cub, i, j) == true)
			{
				error_map_unclosed();
				return (false);
			}
			else if (is_character(cub->map.map[i][j]) == true && check_space(cub, i, j) == true)
			{
				error_start_position(cub->map.map[i][j]);
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
