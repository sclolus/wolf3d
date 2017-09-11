/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj_perspective_transformation.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 10:42:00 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/11 10:42:57 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

inline void	ft_obj_perspective_transformation(t_obj *obj)
{
	uint32_t	i;

	i = 0;
	while (i < obj->nbr_vs)
	{
		obj->vertices[i] = ft_perspective_transformation(obj->vertices[i]);
		i++;
	}
}
