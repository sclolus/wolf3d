/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shade_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 08:12:22 by sclolus           #+#    #+#             */
/*   Updated: 2017/10/03 08:37:11 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

inline int	ft_shade_color(int color, float shading)
{
	t_color		darker_color;

	darker_color.color = color;
	darker_color.component.r = (uint8_t)((float)darker_color.component.r * shading);
	darker_color.component.g = (uint8_t)((float)darker_color.component.g * shading);
	darker_color.component.b = (uint8_t)((float)darker_color.component.b * shading);
	return (darker_color.color);
}
