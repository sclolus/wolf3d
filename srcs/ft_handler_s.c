/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 07:53:30 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/25 07:06:06 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_handler_s(void *param)
{
	t_mlx_data	*mlx_data;
	t_player	*player;
	t_pos		new_pos;
	t_map		*map;

	mlx_data = ((t_mlx_data**)param)[0];
	player = ((t_player**)param)[1];
	new_pos = (t_pos){player->pos.x - cosf(player->angle) * MOVE_COEFF,
					  player->pos.y - sinf(player->angle) * MOVE_COEFF};
	map = ft_get_world_map(mlx_data);
	if (player->pos.x < map->width
		&& player->pos.y < map->height
		&& map->buffer[(uint32_t)new_pos.x + (uint32_t)new_pos.y * map->width].blocking)
		return ;
	else
		player->pos = new_pos;

	ft_bzero(mlx_data->frame->buffer, 4 * WINDOW_WIDTH * WINDOW_HEIGHT);
	ft_raycasting(mlx_data, player);
	mlx_put_image_to_window(mlx_data->connector, mlx_data->win
							, mlx_data->frame->frame, 0, 0);
}
