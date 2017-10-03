/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_skybox.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 03:41:21 by sclolus           #+#    #+#             */
/*   Updated: 2017/10/03 08:21:06 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_apply_skybox(t_mlx_data *data, t_player *player, t_map *map)
{
	int32_t		delta_x;
	uint32_t	pixel_per_rad;
	uint32_t	y;

	if (!map->skybox.width || !map->skybox.height)
		return ;
	pixel_per_rad = (uint32_t)((float)map->skybox.width / ((float)M_PI * 2));
	delta_x = (int32_t)((float)pixel_per_rad * (player->angle + (float)M_PI));
	y = 0;
	while (y < (uint32_t)map->skybox.height)
	{
		ft_memcpy(((int*)data->frame->buffer) + (y * WINDOW_WIDTH)
		, (int*)map->skybox.skybox + (y * (uint32_t)map->skybox.width) + delta_x
		, (size_t)(WINDOW_WIDTH * 4));
		y++;
	}
}
