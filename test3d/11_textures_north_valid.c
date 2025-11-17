/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_textures_north_valid.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 12:49:33 by jutocche          #+#    #+#             */
/*   Updated: 2025/11/17 19:56:41 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


bool verify_textures_with_mlx(t_cub *cub, char *path, char *path_name)
{
	void    *img;
	int width;
	int height;

	width = 100;
	height = 100;

	img = mlx_xpm_file_to_image(cub->mlx, path, &width, &height);
	if (!img)
	{
		ft_printf("Error\nCannot loading texture (MLX) with %s path\n", path_name);
		return (false);
	}
	mlx_destroy_image(cub->mlx, img);
	return (true);
}

bool	is_path_readable_north(t_cub *cub)
{
	cub->file.fd = open(cub->north.path_textures, O_RDONLY);
	if (cub->file.fd < 0)
		return (false);
	return (true);
}

bool	is_file_extension_xpm_correct(char *line)
{
	int		len_file;
	int		index;
	int		i;
	char *to_find;

	len_file = ft_strlen(line);
	index = 0;
	while (line[index] != '.' && line[index] != '\0')
		index++;
	if (len_file - 4 < index)
		return (false);
	index = 0;
	i = 0;
	while (line[index] != '.')
		index++;
	to_find = ".xpm";
	while (line[index + i] && to_find[i] && line[index + i] == to_find[i])
	{
		i++;
		if (line[index + i] == '\0')
			return (true);
	}
	return (false);
}

int	path_textures_north(t_cub *cub)
{
	int start;
	int end;
	int len_path;
	
	start = 0;
	while (cub->file.cub_copy[cub->north.line][cub->north.index_path] == ' '
		&& cub->file.cub_copy[cub->north.line][cub->north.index_path] != '\0')
		cub->north.index_path++;
	if (cub->file.cub_copy[cub->north.line][cub->north.index_path] == '\0')
		return (-1);
	start = cub->north.index_path;
	while (cub->file.cub_copy[cub->north.line][cub->north.index_path] != ' '
		&& cub->file.cub_copy[cub->north.line][cub->north.index_path] != '\0')
		cub->north.index_path++;
	end = cub->north.index_path;
	len_path = end - start;
	if (len_path < 4)
		return (-2);
	cub->north.path_textures = ft_strndup(cub->file.cub_copy[cub->north.line] + start, len_path);
	if (cub->north.path_textures == NULL)
	{
		ft_printf("Error\nft_strndup cub->file.cub_copy[... failed\n");
		return (-3);
	}
	return (0);
}

bool textures_north_valid(t_cub *cub)
{
	int path;

	path = path_textures_north(cub);
	if (path < 0)
	{
		if (path == -1)
			error_empty_path("NO");
		else if (path == -2)
			error_extension_path("NO");
		return (false);
	}
	if (is_file_extension_xpm_correct(cub->north.path_textures) == false)
	{
		error_extension_path("NO");
		return (false);
	}
	close(cub->file.fd);
	if (is_path_readable_north(cub) == false)
	{
		error_no_readable_path("NO");
		return (false);
	}
	return (true);
}
