/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 21:10:09 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/25 02:38:20 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static inline t_block_type	ft_get_current_block_type(t_map *map, t_pos pos)
{
	uint32_t	x;
	uint32_t	y;

	x = (uint32_t)pos.x;
	y = (uint32_t)pos.y;
	if (x < map->width
		&&y < map->height)
		return (map->buffer[x + map->width * y].type);
	return (SUPPORTED_BLOCK_TYPES);
}

static inline void			ft_draw_line(uint32_t x, float distance, t_mlx_data *mlx_data, int color)
{
	uint32_t	i;
	uint32_t	max_y;
	uint32_t	height;

	height = (uint32_t)((WINDOW_HEIGHT / distance));
	if (height > WINDOW_HEIGHT)
		height = WINDOW_HEIGHT;
	i = WINDOW_HEIGHT / 2 - height / 2;
	max_y = WINDOW_HEIGHT / 2 + height / 2;
	while (i <= max_y)
	{
		ft_plot_pixel(x, i, mlx_data->frame->buffer, color);
		++i;
	}
}

static inline void			raycast(t_map *map, uint32_t x, float original_angle, float angle, t_pos pos, t_mlx_data *mlx_data)
{
	t_pos				cpy_pos;
	t_pos				delta_pos;
	t_block_type		type;
	int					color;
	float				distance;

	cpy_pos = pos;
	delta_pos.x = BASE_DISTANCE * cosf(angle);
	delta_pos.y = BASE_DISTANCE * sinf(angle);
	type = AIR;
/* 	while (delta_pos.x + delta_pos.y >= BASE_DISTANCE / 1000) */
/* 	{ */
	while (!(type = ft_get_current_block_type(map, pos)) && type != SUPPORTED_BLOCK_TYPES)
	{
		pos.x += delta_pos.x;
		pos.y += delta_pos.y;
	}
/* 		pos.x -= delta_pos.x; */
/* 		pos.y -= delta_pos.y; */
/* 		delta_pos.x /= 10; */
/* 		delta_pos.y /= 10; */
/* 	} */
	if (type == AIR)
		color = 0xFFFFF;
	else if (type == NORMAL)
		color = 0xFF0000;
	else
		color = 0x0000FF;
	distance = sqrtf(powf(pos.x - cpy_pos.x, 2) + powf(pos.y - cpy_pos.y, 2));
	distance *= cosf(original_angle - angle);
//	printf("d_angle: %lf\n", (double)(original_angle - angle) * 180 / M_PI);
	ft_draw_line(x, distance, mlx_data, color);
}

void				ft_raycasting(t_mlx_data *data, t_player *player)
{
	t_map		*map;
	uint32_t	i;
	float		angle;
	float		delta_angle;

	map = ft_get_world_map();
	angle = player->angle - (float)M_PI / 4;
	delta_angle = (float)M_PI / 2 / WINDOW_WIDTH;
	i = 0;
//	printf("angle: %lf", (double)angle);
	while (i < WINDOW_WIDTH)
	{
		raycast(map, i, player->angle, angle, player->pos, data);
		angle += delta_angle;
		i++;
	}
}
