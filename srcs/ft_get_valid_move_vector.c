/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_valid_move_vector.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 14:54:59 by sclolus           #+#    #+#             */
/*   Updated: 2017/10/03 15:08:13 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

inline t_pos	ft_get_valid_move_vector(t_map *map
										, t_player *player
										, t_pos move)
{
	t_pos	new_pos;

	new_pos = (t_pos){player->pos.x + move.x,
					player->pos.y + move.y};
	if (new_pos.x < 0 || new_pos.x > map->width
		|| map->buffer[(uint32_t)new_pos.x + (uint32_t)player->pos.y
					* map->width].blocking)
		new_pos.x = player->pos.x;
	if (new_pos.y < 0 || new_pos.y > map->height
		|| map->buffer[(uint32_t)player->pos.x + (uint32_t)new_pos.y
					* map->width].blocking)
		new_pos.y = player->pos.y;
	return (new_pos);
}
