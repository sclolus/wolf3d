/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 21:10:09 by sclolus           #+#    #+#             */
/*   Updated: 2017/10/03 15:50:46 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static inline void			ft_draw_line(const uint32_t x, const float distance
										, t_mlx_data *mlx_data, const int color)
{
	uint32_t	i;
	uint32_t	max_y;
	uint32_t	height;

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
		ft_plot_pixel(x, i++, mlx_data->frame->buffer
					, ft_shade_distance(color, distance));
}

static inline int			ft_get_wall_color(int side, t_pos *pos
											, t_pos cpy_pos)
{
	if (side)
	{
		pos->x = FLOORING_DU_TURFU(pos->x);
		return (0xFF0000 + (cpy_pos.x > pos->x) * 0x00FF00);
	}
	else
	{
		pos->y = FLOORING_DU_TURFU(pos->y);
		return (0x0000FF + (cpy_pos.y > pos->y) * 0x00FF00);
	}
}

static inline t_pos			ft_raycast(t_map *map, float angle, t_pos pos
											, int *side)
{
	t_block_type		type;
	t_pos				delta_pos;

	delta_pos.x = BASE_DISTANCE * cosf(angle);
	delta_pos.y = BASE_DISTANCE * sinf(angle);
	type = AIR;
	while (!(type = ft_get_current_block_type(map, pos))
				&& type != SUPPORTED_BLOCK_TYPES)
	{
		pos.x += delta_pos.x;
		if ((type = ft_get_current_block_type(map, pos))
				|| type == SUPPORTED_BLOCK_TYPES)
		{
			*side = 1;
			break ;
		}
		pos.y += delta_pos.y;
		if ((type = ft_get_current_block_type(map, pos))
				|| type == SUPPORTED_BLOCK_TYPES)
		{
			*side = 0;
			break ;
		}
	}
	return (pos);
}

static inline t_ray			raycast(t_map *map, t_player *player
							, float angle)
{
	t_pos				pos;
	t_block_type		type;
	float				distance;
	int					side;
	int					color;

	side = 0;
	pos = ft_raycast(map, angle, player->pos, &side);
	type = ft_get_current_block_type(map, pos);
	color = ft_get_wall_color(side, &pos, player->pos);
	distance = fast_inverse_square_root((player->pos.x - pos.x)
	* (player->pos.x - pos.x) + (player->pos.y - pos.y)
	* (player->pos.y - pos.y));
	distance = 1 / distance;
	color = ft_shade_distance(color, distance);
	distance *= cosf(player->angle - angle);
	return ((t_ray){distance, color});
}

void						ft_rendering(t_mlx_data *data, t_player *player)
{
	t_ray		ray;
	t_map		*map;
	uint32_t	i;
	float		angle;
	float		delta_angle;

	map = ft_get_world_map(data);
	ft_apply_skybox(data, player, map);
	angle = player->angle - (float)M_PI / 6;
	delta_angle = (float)M_PI / 3 / WINDOW_WIDTH;
	i = 0;
	while (i < WINDOW_WIDTH)
	{
		ray = raycast(map, player, angle);
		ft_draw_line(i, ray.distance, data, ray.color);
		angle += delta_angle;
		i++;
	}
	if (!map->buffer[(uint32_t)player->pos.x + (uint32_t)player->pos.y
				* map->width].type)
		ft_raindrops(data);
}
