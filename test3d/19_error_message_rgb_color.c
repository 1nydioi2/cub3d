/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   19_error_message_rgb_color.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:28:53 by jutocche          #+#    #+#             */
/*   Updated: 2025/10/27 09:30:47 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void error_color_out_of_range(char *color)
{
	printf("Error\nAt least one color value is > 255: %s\n", color);
}

void error_unreadable_color(char *color)
{
	printf("Error\nAt least one color setting is invalid or negative: %s\n", color);
}

void	error_setting_color_empty(char *color)
{
	printf("Error\nAt least one empty color setting: %s\n", color);
}

void	error_number_colors(char *color)
{
	printf("Error\nNumber of colors different from three: %s\n", color);
}
