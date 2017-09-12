/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 10:23:37 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/12 09:24:24 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

inline void	ft_draw_obj(t_obj *obj, t_mlx_data *mlx_data)
{
	uint64_t	i;

	i = 0;
	ft_obj_perspective_transformation(obj);
	while (i < obj->nbr_poly)
	{
/* 		printf("poly: %llu vertices 0: x: %lf, y: %lf, z:%lf, w:%lf\n", i, (double)obj->polygones[i].vertices[0].x, (double)obj->polygones[i].vertices[0].y, (double)obj->polygones[i].vertices[0].z, (double)obj->polygones[i].vertices[0].w); */
/* 		printf("poly: %llu vertices 1: x: %lf, y: %lf, z:%lf, w:%lf\n", i, (double)obj->polygones[i].vertices[1].x, (double)obj->polygones[i].vertices[1].y, (double)obj->polygones[i].vertices[1].z, (double)obj->polygones[i].vertices[1].w); */
/* 		printf("poly: %llu vertices 2: x: %lf, y: %lf, z:%lf, w:%lf\n", i, (double)obj->polygones[i].vertices[2].x, (double)obj->polygones[i].vertices[2].y, (double)obj->polygones[i].vertices[2].z, (double)obj->polygones[i].vertices[2].w); */
		ft_draw_polygone(obj->polygones + i++, mlx_data);
	}
}
