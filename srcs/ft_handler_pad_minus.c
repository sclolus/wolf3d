/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_pad_minus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 23:20:21 by sclolus           #+#    #+#             */
/*   Updated: 2017/10/03 08:40:13 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_handler_pad_minus(void *param)
{
	t_map		*map;
	float		delta_shading;

	map = ft_get_world_map(((t_mlx_data**)param)[0]);
	if (*ft_get_rain_factor() > BASE_RAIN_UPPER_LIMIT)
	{
		*ft_get_rain_bool() = 0;
		return ;
	}
	(*ft_get_rain_factor()) += BASE_RAIN_MODIFIER_FACTOR;
	delta_shading = (float)(BASE_RAIN_UPPER_LIMIT - BASE_RAIN_LIMIT) / BASE_RAIN_MODIFIER_FACTOR;
	if (*ft_get_rain_factor() < BASE_RAIN_FACTOR)
		ft_shade_image(map->skybox.skybox, (uint32_t)map->skybox.width
			, (uint32_t)map->skybox.height, 1 / SKYBOX_SHADING_FACTOR);
}
