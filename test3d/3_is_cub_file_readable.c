/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_is_cub_file_readable.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 14:04:54 by jutocche          #+#    #+#             */
/*   Updated: 2025/11/01 16:20:16 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_allocation_cub_copy_success(t_cub *cub)
{
	int	i;

	i = 0;
	cub->file.cub_copy = malloc(sizeof(char *) * (cub->file.line_count + 1));
	if (cub->file.cub_copy == NULL)
	{
		ft_printf("Error\nmalloc cub->cub_copy failed\n");
		free_cub_and_close(cub);
		return (false);
	}
	while (i < cub->file.line_count)
	{
		cub->file.cub_copy[i] = malloc(sizeof(char) * (cub->file.line_len + 1));
		if (cub->file.cub_copy[i] == NULL)
		{
			ft_printf("Error\nmalloc cub->cub_copy[i] failed\n");
			free_cub_and_close(cub);
			return (false);
		}
		i++;
	}
	cub->file.cub_copy[i] = NULL;
	return (true);
}

int	count_i(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n' && line[i] != '\r')
	{
		if (line[i] == '\t')
			i += 4;
		else
			i++;
	}
	return (i);
}

bool	is_line(t_cub *cub, char *line)
{
	if (line == NULL)
	{
		printf("Error\nget next line failed\n");
		free_cub_and_close(cub);
		return (false);
	}
	return (true);
}

int	line_len_and_line_count(t_cub *cub)
{
	char	*line;
	int		i;

	line = get_next_line(cub->file.fd);
	if (is_line(cub, line) == false)
		return (1);
	while (line)
	{
		i = count_i(line);
		if (i > cub->file.line_len)
			cub->file.line_len = i;
		cub->file.line_count++;
		free(line);
		line = get_next_line(cub->file.fd);
	}
	if (line)
		free(line);
	return (0);
}

bool	is_cub_file_readable(t_cub *cub)
{
	cub->file.line_len = 0;
	cub->file.line_count = 0;
	cub->file.total_elements = 0;
	if (line_len_and_line_count(cub) == 1)
		return (false);
	close(cub->file.fd);
	if (is_opening_file_possible(cub) == false)
		return (false);
	if (is_allocation_cub_copy_success(cub) == false)
		return (false);
	fill_cub_copy(cub);
	return (true);
}
