/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 21:10:09 by sclolus           #+#    #+#             */
/*   Updated: 2017/10/02 07:55:04 by sclolus          ###   ########.fr       */
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
		&& y < map->height)
		return (map->buffer[x + map->width * y].type);
	return (SUPPORTED_BLOCK_TYPES);
}

static inline int			ft_shade_distance(int color, float distance)
{
	t_color		darker_color;
	float		shading;

	shading = (1.0f / (distance * distance));
	if (shading > 1)
		shading = 1;
	darker_color.color = color;
	darker_color.component.r = (uint8_t)((float)darker_color.component.r * shading);
	darker_color.component.g = (uint8_t)((float)darker_color.component.g * shading);
	darker_color.component.b = (uint8_t)((float)darker_color.component.b * shading);
	return (darker_color.color);
}

static inline void			ft_draw_line(const uint32_t x, const float distance
										 , t_mlx_data *mlx_data, int color)
{
	uint32_t	i;
	uint32_t	max_y;
	uint32_t	height;
/* 	t_texture	*texture; */
/* 	int32_t		texture_x; */

/* 	texture = ft_get_textures(mlx_data); */
/* 	texture_x = (int)(texture->width * texture_x_f); */
	if (distance >= -0.0001f && distance <= 0.0001f)
		height = WINDOW_HEIGHT;
	else
		height = (uint32_t)(((float)(WINDOW_HEIGHT) / distance));
	if (height > WINDOW_HEIGHT)
		height = WINDOW_HEIGHT;
	i = (WINDOW_HEIGHT / 2) - (height / 2);
	max_y = (WINDOW_HEIGHT / 2) + (height / 2);
	while (i < max_y)
	{
		ft_plot_pixel(x, i, mlx_data->frame->buffer, color);
		++i;
	}
	while (i < WINDOW_HEIGHT)
		ft_plot_pixel(x, i++, mlx_data->frame->buffer, ft_shade_distance(color, distance));
}

#include <stdio.h>

static inline void			raycast(t_map *map, uint32_t x, float original_angle, float angle, t_pos pos, t_mlx_data *mlx_data)
{
	t_pos				cpy_pos;
	t_pos				delta_pos;
	t_block_type		type;
	float				distance;
	int					side;
	int					color;

	cpy_pos = pos;
	delta_pos.x = BASE_DISTANCE * cosf(angle);
	delta_pos.y = BASE_DISTANCE * sinf(angle);
	type = AIR;
	side = 0;
	while (!(type = ft_get_current_block_type(map, pos)) && type != SUPPORTED_BLOCK_TYPES)
	{
		pos.x += delta_pos.x;
		if ((type = ft_get_current_block_type(map, pos)) || type == SUPPORTED_BLOCK_TYPES)
		{
			side = 1;
			break ;
		}
		pos.y += delta_pos.y;
		if ((type = ft_get_current_block_type(map, pos)) || type == SUPPORTED_BLOCK_TYPES)
		{
			side = 0;
			break ;
		}
	}
	if (side)
	{
		pos.x = FLOORING_DU_TURFU(pos.x);
		color = 0xFF0000 + (cpy_pos.x > pos.x) * 0x00FF00;
	}
	else
	{
		pos.y = FLOORING_DU_TURFU(pos.y);
		color = 0x0000FF + (cpy_pos.y > pos.y) * 0x00FF00;
	}
	distance = sqrtf(powf(pos.x - cpy_pos.x, 2) + powf(pos.y - cpy_pos.y, 2));
	color = ft_shade_distance(color, distance);
	distance *= cosf(original_angle - angle);
	ft_draw_line(x, distance, mlx_data, color);
}

void				ft_raycasting(t_mlx_data *data, t_player *player)
{
	t_map		*map;
	uint32_t	i;
	float		angle;
	float		delta_angle;

	map = ft_get_world_map(data);
	ft_apply_skybox(data, player, map);
	angle = player->angle - (float)M_PI / 4;
	delta_angle = (float)M_PI / 2 / WINDOW_WIDTH;
	i = 0;
	while (i < WINDOW_WIDTH)
	{
		raycast(map, i, player->angle, angle, player->pos, data);
		angle += delta_angle;
		i++;
	}
	if (!map->buffer[(uint32_t)player->pos.x  + (uint32_t)player->pos.y * map->width].type)
		ft_raindrops(data);
}
