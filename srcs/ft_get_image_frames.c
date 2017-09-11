/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_image_frames.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 18:43:15 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/10 22:22:32 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_image_frame	*ft_get_image_frames(t_mlx_ptr connector, uint32_t nbr_frames)
{
	t_image_frame		*frames;
	uint32_t			i;

	i = 0;
	if (!(frames = (t_image_frame*)ft_memalloc(sizeof(t_image_frame)
							* nbr_frames)))
		ft_error_exit(1, (char*[]){MLX_IMG_FRAMES_ERROR}, EXIT_FAILURE);
	while (i < nbr_frames)
	{
		if (!(frames[i].frame = mlx_new_image(connector, WINDOW_WIDTH
											, WINDOW_HEIGHT)))
			ft_error_exit(1, (char*[]){MLX_NEW_IMG_ERROR}, EXIT_FAILURE);
		frames[i].buffer = mlx_get_data_addr(frames[i].frame
						, &frames[i].bits_per_pixel, &frames[i].size_line
						, &frames[i].endian);
		frames[i].state = AVAILABLE;
		i++;
	}
	return (frames);
}
