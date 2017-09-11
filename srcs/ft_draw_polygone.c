/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_polygone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 00:30:54 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/11 05:49:20 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

inline float	ft_max_float(float a, float b)
{
	return (a > b ? a : b);
}

inline float	ft_min_float(float a, float b)
{
	return (a < b ? a : b);
}

inline void		ft_get_min_max_coords(t_polygone *polygone, uint32_t *max_coords
									, uint32_t *min_coords)
{
	max_coords[0] = (uint32_t)(ft_max_float(polygone->vertices[0].x
	, ft_max_float(polygone->vertices[1].x, polygone->vertices[2].x)));
	max_coords[1] = (uint32_t)(ft_max_float(polygone->vertices[0].y
	, ft_max_float(polygone->vertices[1].y, polygone->vertices[2].y)));
	min_coords[0] = (uint32_t)(ft_min_float(polygone->vertices[0].x
	, ft_min_float(polygone->vertices[1].x, polygone->vertices[2].x)));
	min_coords[1] = (uint32_t)(ft_min_float(polygone->vertices[0].y
	, ft_min_float(polygone->vertices[1].y, polygone->vertices[2].y)));
}

inline float	ft_cross_product(const t_float2 a, const t_float2 b)
{
	return (a.x * b.y - a.y * b.x);
}

inline void		ft_draw_polygone(t_polygone *polygone, t_mlx_data *mlx_data)
{
	uint32_t	max_coords[2];
	uint32_t	min_coords[2];
	uint32_t	x;
	uint32_t	y;
	t_float2	vs1;
	t_float2	vs2;
	float		base_cross_product;
	t_float2	actual;
	t_float2	results;

	ft_get_min_max_coords(polygone, max_coords, min_coords);
	vs1 = (t_float2){polygone->vertices[1].x - polygone->vertices[0].x, polygone->vertices[1].y - polygone->vertices[0].y};
	vs2 = (t_float2){polygone->vertices[2].x - polygone->vertices[0].x, polygone->vertices[2].y - polygone->vertices[0].y};
	base_cross_product = ft_cross_product(vs1, vs2);
	y = min_coords[1];
	while (y < max_coords[1])
	{
		x = min_coords[0];
		while (x < max_coords[0])
		{
			actual = (t_float2){x - polygone->vertices[0].x, y - polygone->vertices[0].y};
			results = (t_float2){ft_cross_product(actual, vs2) / base_cross_product, ft_cross_product(vs1, actual) / base_cross_product};
			if ((results.x >= 0) && (results.y >= 0) && (results.x + results.y <= 1))
				ft_plot_pixel(x, y, mlx_data->frame->buffer, (polygone->color));
			x++;
		}
		y++;
	}
}
