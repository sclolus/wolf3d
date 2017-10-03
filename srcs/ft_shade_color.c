/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shade_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 08:12:22 by sclolus           #+#    #+#             */
/*   Updated: 2017/10/03 14:34:51 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

inline int	ft_shade_distance(const int color
								, const float distance)
{
	t_color		darker_color;
	float		shading;

	shading = (1.0f / (distance * distance));
	if (shading > 1)
		shading = 1;
	darker_color.color = color;
	darker_color.component.r = (uint8_t)((float)darker_color.component.r
										* shading);
	darker_color.component.g = (uint8_t)((float)darker_color.component.g
										* shading);
	darker_color.component.b = (uint8_t)((float)darker_color.component.b
										* shading);
	return (darker_color.color);
}

inline int	ft_shade_color(int color, float shading)
{
	t_color		darker_color;

	darker_color.color = color;
	darker_color.component.r = (uint8_t)((float)darker_color.component.r
										* shading);
	darker_color.component.g = (uint8_t)((float)darker_color.component.g
										* shading);
	darker_color.component.b = (uint8_t)((float)darker_color.component.b
										* shading);
	return (darker_color.color);
}
