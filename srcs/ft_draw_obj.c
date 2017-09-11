/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 10:23:37 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/11 10:35:10 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

inline void	ft_draw_obj(t_obj *obj, t_mlx_data *mlx_data)
{
	uint32_t	i;

	i = 0;
	while (i < obj->nbr_poly)
		ft_draw_polygone(obj->polygones + i++, mlx_data);
}
