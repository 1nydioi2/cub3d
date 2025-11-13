/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_is_name_file_correct.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 10:46:50 by jutocche          #+#    #+#             */
/*   Updated: 2025/10/26 18:15:48 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_file_extension_cub_correct(char *file)
{
	int		len_file;
	char	*to_find;
	int		index;
	int		i;

	len_file = ft_strlen(file);
	if (len_file < 4)
		return (false);
	to_find = ".cub";
	index = 0;
	while (file[index] != '.' && file[index] != '\0')
		index++;
	if (len_file - 4 < index)
		return (false);
	index = 0;
	i = 0;
	while (file[index] != '.')
		index++;
	while (file[index + i] && to_find[i] && file[index + i] == to_find[i])
	{
		i++;
		if (file[index + i] == '\0')
			return (true);
	}
	return (false);
}

bool	is_file_argument(char *argv)
{
	if (argv == NULL)
		return (false);
	return (true);
}

bool	is_number_argument_correct(int argc)
{
	if (argc != 2)
		return (false);
	return (true);
}

bool	is_name_file_correct(int argc, char *argv)
{
	if (is_number_argument_correct(argc) == false)
	{
		ft_printf("Error\nUsage: ./cub3d *.cub\n");
		return (false);
	}
	if (is_file_argument(argv) == false)
	{
		ft_printf("Error\nFile name empty\n");
		return (false);
	}
	if (is_file_extension_cub_correct(argv) == false)
	{
		ft_printf("Error\nWrong extension file .cub\n");
		return (false);
	}
	return (true);
}
