/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plot_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 01:20:02 by sclolus           #+#    #+#             */
/*   Updated: 2017/10/03 10:47:11 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

inline void	ft_plot_pixel(uint32_t x, uint32_t y, int *image, int color)
{
	if (x <= WINDOW_WIDTH - 1 && y <= WINDOW_HEIGHT - 1)
		image[y * WINDOW_WIDTH + x] = color;
}
