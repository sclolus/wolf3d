/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raindrops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 04:48:32 by sclolus           #+#    #+#             */
/*   Updated: 2017/10/03 10:41:15 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

inline void	ft_raindrops(t_mlx_data *data)
{
	uint64_t	raindrops_nbr;
	uint32_t	rain_width;
	uint32_t	x;
	uint32_t	y;
	uint32_t	i;

	if (!*ft_get_rain_bool())
		return ;
	raindrops_nbr = ft_random() % (WINDOW_WIDTH * WINDOW_HEIGHT
								/ *ft_get_rain_factor());
	while (raindrops_nbr--)
	{
		x = ft_random() % WINDOW_WIDTH;
		y = ft_random() % WINDOW_HEIGHT;
		rain_width = ft_random() % 50;
		i = 0;
		while (i < rain_width)
		{
			ft_plot_pixel(x, y + i
				, data->frame->buffer, (int)0xA9FFFFFF);
			i++;
		}
	}
}
