/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_skybox.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 03:41:21 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/25 08:16:56 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_apply_skybox(t_mlx_data *data, t_player *player, t_map *map)
{
	int32_t		delta_x;
	int32_t		delta_y;
	int32_t		y;

	if (map->skybox.height > WINDOW_HEIGHT)
		delta_y = map->skybox.height / 2 - WINDOW_HEIGHT / 8;
	else
		delta_y = 0;
	delta_x = (int)(WINDOW_WIDTH / 2 * player->angle);
	y = 0;
//	printf("delta_x: %d\n", delta_x);
	int32_t	width;

	if (delta_x + WINDOW_WIDTH >= map->skybox.width)
		width = (delta_x + WINDOW_WIDTH) - map->skybox.width;
	else
		width = WINDOW_WIDTH;
	while (y < WINDOW_HEIGHT)
	{
		ft_memcpy((int*)data->frame->buffer + y * WINDOW_WIDTH, (int*)map->skybox.skybox
				  + (delta_y + y) * map->skybox.width + delta_x, (uint32_t)width * 4);
		y++;
	}
/* 	y = 0; */
/* 	width = WINDOW_WIDTH - width; */
/* 	delta_x = WINDOW_WIDTH - width; */
/* 	while (y < WINDOW_HEIGHT) */
/* 	{ */
/* 		ft_memcpy((int*)data->frame->buffer + y * WINDOW_WIDTH + delta_x, (int*)map->skybox.skybox */
/* 				  + (delta_y + y) * map->skybox.width, (uint32_t)width * 4); */
/* 		y++; */
/* 	} */
}
