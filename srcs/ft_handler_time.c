/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 23:05:24 by sclolus           #+#    #+#             */
/*   Updated: 2017/10/02 23:11:07 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	ft_handler_time(void *param)
{
	t_mlx_data	*mlx_data;
	t_player	*player;

	mlx_data = ((t_mlx_data**)param)[0];
	player = ((t_player**)param)[1];
	ft_bzero(mlx_data->frame->buffer, 4 * WINDOW_WIDTH * WINDOW_HEIGHT);
	ft_raycasting(mlx_data, player);
	mlx_put_image_to_window(mlx_data->connector, mlx_data->win
						, mlx_data->frame->frame, 0, 0);
	return (1);
}
