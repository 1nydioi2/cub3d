/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   17_rgb_floor_split_and_atoi.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:46:57 by jutocche          #+#    #+#             */
/*   Updated: 2025/11/01 16:04:32 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	atoi_color_rgb(char *str)
{
	int	result;
	int	i;
	
	if (!str || !str[0])
		return (-3);
	result = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] == '+' || (str[i] >= '0' && str[i] <= '9')))
			return (-4);
		i++;
	}
	i = 0;
	while (str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		if (result > 255)
			return (-5);
		i++;
	}
	return (result);
}

char	*setting_to_color(char *setting, int *index)
{
	int		i;
	int		start;
	char	*color;

	i = 0;
	while (setting[*index] == ',' || setting[*index] == ' ')
		(*index)++;
	start = *index;
	while (setting[*index] != '\0' && setting[*index] != ',' && setting[*index] != ' ')
		(*index)++;
	color = malloc(sizeof(char) * (*index - start + 1));
	if (color == NULL)
	{
		ft_printf("Error\nMalloc color failed\n");
		return (NULL);
	}
	while (start < *index)
	{
		color[i] = setting[start];
		i++;
		start++;
	}
	color[i] = '\0';
	return (color);
}

int	count_color_rgb(char *rgb_setting)
{
	int	i;
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	i = 0;
	while (rgb_setting[i] != '\0')
	{
		if (rgb_setting[i] != ',')
		{
			if (in_word == 0)
			{
				in_word = 1;
				count++;
			}
		}
		else
			in_word = 0;
		i++;
	}
	return (count);
}

int	split_cub_rgb_floor(t_cub *cub, char *rgb_setting)
{
	int		total_color;
	int		count;
	int		i;

	count = 0;
	i = 0;
	total_color = count_color_rgb(rgb_setting);
	if (total_color != 3)
		return (-1);
	cub->floor.rgb_color = malloc(sizeof(char *) * (total_color + 1)); 
	if (cub->floor.rgb_color == NULL)
	{
		ft_printf("Error\nMalloc floor.rgb_color failed\n");
		return (-2);
	}
	while (count < total_color)
	{
		cub->floor.rgb_color[count] = setting_to_color(rgb_setting, &i);
		count++;
	}
	cub->floor.rgb_color[total_color] = NULL;
	return (0);
}

int	split_and_atoi_rgb_floor(t_cub *cub)
{
	int start;
	int rgb_setting;

	start = cub->floor.index_rgb;
	while (cub->file.cub_copy[cub->floor.line][cub->floor.index_rgb] == ' '
		&& cub->file.cub_copy[cub->floor.line][cub->floor.index_rgb] != '\0')
		cub->floor.index_rgb++;
	rgb_setting = split_cub_rgb_floor(cub, cub->file.cub_copy[cub->floor.line] + cub->floor.index_rgb);
	if (rgb_setting < 0)
		return (rgb_setting);
	start = 0;
	cub->floor.value_color = malloc(sizeof(int) * 3);
	if (cub->floor.value_color == NULL)
	{
		ft_printf("Error\nMalloc cub->floor.value_color failed\n");
		return (-2);
	}
	while (start < 3)
	{
		cub->floor.value_color[start] = atoi_color_rgb(cub->floor.rgb_color[start]); 
		if (cub->floor.value_color[start] < 0)
			return (cub->floor.value_color[start]);
		start++;
	}
	return (1);
}
