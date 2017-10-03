/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 22:14:10 by sclolus           #+#    #+#             */
/*   Updated: 2017/10/03 10:49:07 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static inline void	ft_set_mlx_hooks(t_mlx_data *mlx_data, void **params)
{
	mlx_hook(mlx_data->win, KEYPRESS, KEYPRESSMASK, &ft_handler_keys
		, params);
	mlx_hook(mlx_data->win, KEYRELEASE, KEYRELEASEMASK
		, &ft_handler_keys_release
		, params);
	mlx_loop_hook(mlx_data->connector, &ft_handler_time
		, params);
}

int					main(void)
{
	t_mlx_data	mlx_data;
	t_player	player;

	if (!(mlx_data.connector = mlx_init()))
		ft_error_exit(1, (char*[]){MLX_INIT_ERROR}, EXIT_FAILURE);
	if (!(mlx_data.win = mlx_new_window(mlx_data.connector, WINDOW_WIDTH
										, WINDOW_HEIGHT, WINDOW_NAME)))
		ft_error_exit(1, (char*[]){MLX_NEW_WIN_ERROR}, EXIT_FAILURE);
	mlx_data.frame = ft_get_image_frames(mlx_data.connector, NBR_IMAGE_FRAME);
	player = (t_player){{1.5, 1.5}, 0};
	ft_raycasting(&mlx_data, &player);
	mlx_put_image_to_window(mlx_data.connector, mlx_data.win
							, mlx_data.frame->frame, 0, 0);
	ft_set_mlx_hooks(&mlx_data, (void*[]){&mlx_data, &player});
	mlx_loop(mlx_data.connector);
}
