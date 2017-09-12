/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj_perspective_transformation.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 10:42:00 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/12 12:02:59 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

inline void	ft_obj_perspective_transformation(t_obj *obj)
{
	uint64_t	i;

	i = 0;
	while (i < obj->nbr_vs)
	{
		printf("\nbefore: vertices :%llu x: %lf, y: %lf, z:%lf, w:%lf\n", i, (double)obj->vertices[i].x, (double)obj->vertices[i].y, (double)obj->vertices[i].z, (double)obj->vertices[i].w);
		obj->result_vertices[i] = ft_perspective_transformation(obj->vertices[i]);
		printf("after: vertices :%llu x: %lf, y: %lf, z:%lf, w:%lf\n", i, (double)obj->vertices[i].x, (double)obj->vertices[i].y, (double)obj->vertices[i].z, (double)obj->vertices[i].w);
		i++;
	}
}
