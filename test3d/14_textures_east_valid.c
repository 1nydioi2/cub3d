/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   14_textures_east_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Creastted: 2025/10/25 12:49:33 by jutocche          #+#    #+#             */
/*   Updated: 2025/10/26 16:11:19 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_path_readable_east(t_cub *cub)
{
	cub->file.fd = open(cub->east.path_textures, O_RDONLY);
	if (cub->file.fd < 0)
		return (false);
	return (true);
}

int	path_textures_east(t_cub *cub)
{
	int start;
	int end;
	int len_path;
	
	start = 0;
	while (cub->file.cub_copy[cub->east.line][cub->east.index_path] == ' '
		&& cub->file.cub_copy[cub->east.line][cub->east.index_path] != '\0')
		cub->east.index_path++;
	if (cub->file.cub_copy[cub->east.line][cub->east.index_path] == '\0')
		return (-1);
	start = cub->east.index_path;
	while (cub->file.cub_copy[cub->east.line][cub->east.index_path] != ' '
		&& cub->file.cub_copy[cub->east.line][cub->east.index_path] != '\0')
		cub->east.index_path++;
	end = cub->east.index_path;
	len_path = end - start;
	if (len_path < 4)
		return (-2);
	cub->east.path_textures = ft_strndup(cub->file.cub_copy[cub->east.line] + start, len_path);
	if (cub->east.path_textures == NULL)
	{
		ft_printf("Error\nft_strndup cub->file.cub_copy[... failed\n");
		return (-3);
	}
	return (0);
}

bool textures_east_valid(t_cub *cub)
{
	int path;

	path = path_textures_east(cub);
	if (path < 0)
	{
		if (path == -1)
			error_empty_path("EA");
		else if (path == -2)
			error_extension_path("EA");
		return (false);
	}
	if (is_file_extension_xpm_correct(cub->east.path_textures) == false)
	{
		error_extension_path("EA");
		return (false);
	}
	close(cub->file.fd);
	if (is_path_readable_east(cub) == false)
	{
		error_no_readable_path("EA");
		return (false);
	}
	return (true);
}
