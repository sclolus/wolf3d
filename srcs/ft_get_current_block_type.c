/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_current_block_type.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 14:34:25 by sclolus           #+#    #+#             */
/*   Updated: 2017/10/03 14:34:32 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

inline t_block_type	ft_get_current_block_type(t_map *map
											, const t_pos pos)
{
	uint32_t	x;
	uint32_t	y;

	x = (uint32_t)pos.x;
	y = (uint32_t)pos.y;
	if (x < map->width
		&& y < map->height)
		return (map->buffer[x + map->width * y].type);
	return (SUPPORTED_BLOCK_TYPES);
}
