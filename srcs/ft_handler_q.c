/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_q.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 00:16:32 by sclolus           #+#    #+#             */
/*   Updated: 2017/10/03 09:09:33 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_handler_q(void *param)
{
	t_mlx_data	*mlx_data;
	t_player	*player;
	t_map		*map;
	t_pos		delta;

	mlx_data = ((t_mlx_data**)param)[0];
	map = ft_get_world_map(mlx_data);
	player = ((t_player**)param)[1];
	delta.x = 1 * cosf(player->angle) + player->pos.x;
	delta.y = 1 * sinf(player->angle) + player->pos.y;
	if (delta.x >= map->width
		|| delta.y >= map->height || ((uint32_t)delta.x == (uint32_t)player->pos.x
		&& (uint32_t)delta.y == (uint32_t)player->pos.y))
		return ;
	else
	{
		if (map->buffer[(uint32_t)delta.x + (uint32_t)delta.y * map->width].type)
			map->buffer[(uint32_t)delta.x + (uint32_t)delta.y * map->width].blocking = 0;
		else
			map->buffer[(uint32_t)delta.x + (uint32_t)delta.y * map->width].blocking = 1;
		map->buffer[(uint32_t)delta.x + (uint32_t)delta.y * map->width].type ^= 1;
	}
	ft_bzero(mlx_data->frame->buffer, 4 * WINDOW_WIDTH * WINDOW_HEIGHT);
	ft_raycasting(mlx_data, player);
	mlx_put_image_to_window(mlx_data->connector, mlx_data->win
							, mlx_data->frame->frame, 0, 0);
}
