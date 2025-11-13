/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15_error_message_textures.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 12:51:57 by jutocche          #+#    #+#             */
/*   Updated: 2025/10/27 09:30:58 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void error_no_readable_path(char *path)
{
	printf("Error\nCould not open path's texture: %s\n", path);
}

void	error_extension_path(char *path)
{
	ft_printf("Error\nWrong extension path's texture: %s\n", path);
}

void	error_empty_path(char *path)
{
	printf("Error\nEmpty extension to texture: %s\n", path);
}
