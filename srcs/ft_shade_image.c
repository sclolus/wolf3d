/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shade_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 08:15:00 by sclolus           #+#    #+#             */
/*   Updated: 2017/10/03 08:44:07 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_shade_image(int *image, uint32_t width
					, uint32_t height, float shading)
{
	uint64_t	i;
	uint64_t	size;

	size = height * width;
	i = 0;
	while (i < size)
	{
		image[i] = ft_shade_color(image[i], shading);
		i++;
	}
}
