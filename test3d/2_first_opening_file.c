/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_first_opening_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:02:21 by jutocche          #+#    #+#             */
/*   Updated: 2025/11/01 15:59:58 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_opening_file_possible(t_cub *cub)
{
	cub->file.fd = open(cub->file.filename, O_RDONLY);
	if (cub->file.fd < 0)
	{
		ft_printf("Error\nCould not open file\n");
		free_cub_and_close(cub);
		return (false);
	}
	return (true);
}

bool	first_opening_file(t_cub *cub, char *file)
{
	cub->file.filename = ft_strdup(file);
	if (cub->file.filename == NULL)
	{
		ft_printf("Error\nft_strdup cub->filename failed\n");
		return (false);
	}
	if (is_opening_file_possible(cub) == false)
		return (false);
	return (true);
}
