/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_fill_cub_copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 15:49:31 by jutocche          #+#    #+#             */
/*   Updated: 2025/11/01 16:00:44 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int fill_cub_copy_utils(t_cub *cub, int i, int j, char *line)
{
	int tab;

	tab = 0;
	if (j >= cub->file.line_len)
		return (j);
	if (!line[j])
		return (j);
	if (line[j] == '\t')
	{
		while (tab < 4 && j < cub->file.line_len)
		{
			cub->file.cub_copy[i][j] = ' ';
			j++;
			tab++;
		}
	}
	else if (line[j] != '\n' && line[j] != '\r' && line[j] != '\0')
	{
		cub->file.cub_copy[i][j] = line[j];
		j++;
	}
	return (j);
}

void fill_cub_copy(t_cub *cub)
{
	char *line;
	int i;
	int j;

	line = get_next_line(cub->file.fd);
	i = 0;
	while (line && i < cub->file.line_count)
	{
		j = 0;
		while (j < cub->file.line_len && line[j] && line[j] != '\n' && line[j] != '\r')
		{
			j = fill_cub_copy_utils(cub, i, j, line);
		}
		while (j < cub->file.line_len)
		{
			cub->file.cub_copy[i][j] = ' ';
			j++;
		}
		cub->file.cub_copy[i][j] = '\0';
		i++;
		free(line);
		line = get_next_line(cub->file.fd);
	}
	if (line)
		free(line);
}
