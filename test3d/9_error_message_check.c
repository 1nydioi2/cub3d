/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_error_message_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:43:10 by jutocche          #+#    #+#             */
/*   Updated: 2025/11/01 16:02:35 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void error_missing_map(t_cub *cub)
{
	int i;

	i = 7 - cub->file.total_elements;
	if (cub->map.present == 0 && i == 1)
		ft_printf("Error\nMap is missing (but 6 others elements are presents).\n");
	else if (cub->map.present == 0 && i > 1)
		ft_printf("Error\nMap and %d elements are missing.\n", i);
}
void error_invalid_element(void)
{
	printf("Error\nUnknown element in file .cub. 6 elements are required (NO, SO, WE, EA, F, C) and in last the map.\n");
}

void error_number_element(char *element)
{
	printf("Error\nToo many element %s in file .cub\n", element);
}

void error_map_unclosed()
{
	printf("Error\nAt least one wall is missing to close the map.\n");
}

void error_start_position(char c)
{
	printf("Error\nAt least one player '%c' access outside of the map.\n", c);
}
