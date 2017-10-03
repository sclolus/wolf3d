/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 23:05:24 by sclolus           #+#    #+#             */
/*   Updated: 2017/10/03 16:09:25 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	ft_handler_time(void *param)
{
	static clock_t		old_time = 0;
	static clock_t		current_time = 0;
	t_mlx_data			*mlx_data;
	t_player			*player;

	old_time = current_time;
	current_time = clock();
	if (current_time - old_time < CLOCKS_PER_SEC / FPS_LIMIT)
		usleep((useconds_t)(CLOCKS_PER_SEC / FPS_LIMIT
							- (current_time - old_time)));
	mlx_data = ((t_mlx_data**)param)[0];
	player = ((t_player**)param)[1];
	ft_handler_keys(~0, param);
	ft_rendering(mlx_data, player);
	mlx_put_image_to_window(mlx_data->connector, mlx_data->win
						, mlx_data->frame->frame, 0, 0);
	if (*ft_get_fps_bool())
		ft_put_fps(mlx_data, CLOCKS_PER_SEC / (current_time - old_time));
	return (1);
}
