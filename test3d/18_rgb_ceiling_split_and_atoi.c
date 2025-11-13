/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   18_rgb_ceiling_split_and_atoi.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:17:16 by jutocche          #+#    #+#             */
/*   Updated: 2025/11/01 16:04:35 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	split_cub_rgb_ceiling(t_cub *cub, char *rgb_setting)
{
	int		total_color;
	int		count;
	int		i;

	count = 0;
	i = 0;
	total_color = count_color_rgb(rgb_setting);
	if (total_color != 3)
		return (-1);
	cub->ceiling.rgb_color = malloc(sizeof(char *) * (total_color + 1)); 
	if (cub->ceiling.rgb_color == NULL)
	{
		ft_printf("Error\nMalloc cub->ceiling.rgb_color failed\n");
		return (-2);
	}
	while (count < total_color)
	{
		cub->ceiling.rgb_color[count] = setting_to_color(rgb_setting, &i);
		count++;
	}
	cub->ceiling.rgb_color[total_color] = NULL;
	return (0);
}

int	split_and_atoi_rgb_ceiling(t_cub *cub)
{
	int start;
	int rgb_setting;
	
	start = cub->ceiling.index_rgb;
	while (cub->file.cub_copy[cub->ceiling.line][cub->ceiling.index_rgb] == ' '
		&& cub->file.cub_copy[cub->ceiling.line][cub->ceiling.index_rgb] != '\0')
		cub->ceiling.index_rgb++;
	rgb_setting = split_cub_rgb_ceiling(cub, cub->file.cub_copy[cub->ceiling.line] + cub->ceiling.index_rgb);
	if (rgb_setting < 0)
		return (rgb_setting);
	start = 0;
	cub->ceiling.value_color = malloc(sizeof(int) * 3);
	if (cub->ceiling.value_color == NULL)
	{
		ft_printf("Error\nMalloc cub->ceiling.value_color failed\n");
		return (-2);
	}
	while (start < 3)
	{
		cub->ceiling.value_color[start] = atoi_color_rgb(cub->ceiling.rgb_color[start]); 
		if (cub->ceiling.value_color[start] < 0)
			return (cub->ceiling.value_color[start]);
		start++;
	}
	return (1);
}
