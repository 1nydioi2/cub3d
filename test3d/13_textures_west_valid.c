/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_textures_west_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 12:49:33 by jutocche          #+#    #+#             */
/*   Updated: 2025/10/26 18:02:06 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_path_readable_west(t_cub *cub)
{
	cub->file.fd = open(cub->west.path_textures, O_RDONLY);
	if (cub->file.fd < 0)
		return (false);
	return (true);
}

int	path_textures_west(t_cub *cub)
{
	int start;
	int end;
	int len_path;
	
	start = 0;
	while (cub->file.cub_copy[cub->west.line][cub->west.index_path] == ' '
		&& cub->file.cub_copy[cub->west.line][cub->west.index_path] != '\0')
		cub->west.index_path++;
	if (cub->file.cub_copy[cub->west.line][cub->west.index_path] == '\0')
		return (-1);
	start = cub->west.index_path;
	while (cub->file.cub_copy[cub->west.line][cub->west.index_path] != ' '
		&& cub->file.cub_copy[cub->west.line][cub->west.index_path] != '\0')
		cub->west.index_path++;
	end = cub->west.index_path;
	len_path = end - start;
	if (len_path < 4)
		return (-2);
	cub->west.path_textures = ft_strndup(cub->file.cub_copy[cub->west.line] + start, len_path);
	if (cub->west.path_textures == NULL)
	{
		ft_printf("Error\nft_strndup cub->file.cub_copy[... failed\n");
		return (-3);
	}
	return (0);
}

bool textures_west_valid(t_cub *cub)
{
	int path;

	path = path_textures_west(cub);
	if (path < 0)
	{
		if (path == -1)
			error_empty_path("WE");
		else if (path == -2)
			error_extension_path("WE");
		return (false);
	}
	if (is_file_extension_xpm_correct(cub->west.path_textures) == false)
	{
		error_extension_path("WE");
		return (false);
	}
	close(cub->file.fd);
	if (is_path_readable_west(cub) == false)
	{
		error_no_readable_path("WE");
		return (false);
	}
	return (true);
}
