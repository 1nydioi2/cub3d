/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_cub3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:28:15 by jutocche          #+#    #+#             */
/*   Updated: 2025/11/01 16:22:20 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	cub;
	if (is_name_file_correct(argc, argv[1]) == false)
		return (-1);
	if (first_opening_file(&cub, argv[1]) == false)
		return (-3);
	if (is_cub_file_readable(&cub) == false)
		return (-4);
	if (init_mlx(&cub) == false)
		return (-5);
	if (is_data_cub_file_valid(&cub) == false)
		return (-6);
	if (start_cub(&cub) == -1)
		return (-7);



	free_cub_and_close(&cub);
	return (0);
}
