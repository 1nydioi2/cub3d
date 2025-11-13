/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_textures_south_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 12:49:33 by jutocche          #+#    #+#             */
/*   Updated: 2025/10/26 16:10:57 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_path_readable_south(t_cub *cub)
{
	cub->file.fd = open(cub->south.path_textures, O_RDONLY);
	if (cub->file.fd < 0)
		return (false);
	return (true);
}

int	path_textures_south(t_cub *cub)
{
	int start;
	int end;
	int len_path;
	
	start = 0;
	while (cub->file.cub_copy[cub->south.line][cub->south.index_path] == ' '
		&& cub->file.cub_copy[cub->south.line][cub->south.index_path] != '\0')
		cub->south.index_path++;
	if (cub->file.cub_copy[cub->south.line][cub->south.index_path] == '\0')
		return (-1);
	start = cub->south.index_path;
	while (cub->file.cub_copy[cub->south.line][cub->south.index_path] != ' '
		&& cub->file.cub_copy[cub->south.line][cub->south.index_path] != '\0')
		cub->south.index_path++;
	end = cub->south.index_path;
	len_path = end - start;
	if (len_path < 4)
		return (-2);
	cub->south.path_textures = ft_strndup(cub->file.cub_copy[cub->south.line] + start, len_path);
	if (cub->south.path_textures == NULL)
	{
		ft_printf("Error\nft_strndup cub->file.cub_copy[... failed\n");
		return (-3);
	}
	return (0);
}

bool textures_south_valid(t_cub *cub)
{
	int path;

	path = path_textures_south(cub);
	if (path < 0)
	{
		if (path == -1)
			error_empty_path("SO");
		else if (path == -2)
			error_extension_path("SO");
		return (false);
	}
	if (is_file_extension_xpm_correct(cub->south.path_textures) == false)
	{
		error_extension_path("SO");
		return (false);
	}
	close(cub->file.fd);
	if (is_path_readable_south(cub) == false)
	{
		error_no_readable_path("SO");
		return (false);
	}
	return (true);
}
