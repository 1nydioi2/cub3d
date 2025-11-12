/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:35:59 by nilamber          #+#    #+#             */
/*   Updated: 2025/11/12 14:40:57 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	w_put_img(t_data *_data, void *img, int x, int y)
{
	mlx_put_image_to_window(_data->mlx, _data->win, img, x, y);
	return ;
}
