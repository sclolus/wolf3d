/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 07:55:16 by sclolus           #+#    #+#             */
/*   Updated: 2017/10/03 10:45:01 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_handler_d(void *param)
{
	t_mlx_data	*mlx_data;
	t_player	*player;

	mlx_data = ((t_mlx_data**)param)[0];
	player = ((t_player**)param)[1];
	player->angle += ROTATION_COEFF;
	if (player->angle >= (float)M_PI)
		player->angle -= (float)M_PI * 2;
	ft_bzero(mlx_data->frame->buffer, 4 * WINDOW_WIDTH * WINDOW_HEIGHT);
	ft_raycasting(mlx_data, player);
	mlx_put_image_to_window(mlx_data->connector, mlx_data->win
							, mlx_data->frame->frame, 0, 0);
}
