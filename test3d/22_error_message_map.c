/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   22_error_message_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:12:39 by jutocche          #+#    #+#             */
/*   Updated: 2025/10/29 16:34:47 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void error_count_player(int count)
{
	int difference;
	
	if (count == 0)
		printf("Error\nNo player on the map.\n");
	else 
	{
		difference = count - 1;
		if (difference == 1)
			printf("Error\n%d player too many on the map.\n", difference);
		else
			printf("Error\n%d players too many on the map.\n", difference);
	}
}

void error_wrong_character(char c)
{
	printf("Error\nAt least one wrong character in map: %c\n", c);
}
