/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_w.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 07:54:01 by sclolus           #+#    #+#             */
/*   Updated: 2017/10/03 15:11:02 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_handler_w(void *param)
{
	t_pos		move;
	t_mlx_data	*mlx_data;
	t_player	*player;
	t_map		*map;

	mlx_data = ((t_mlx_data**)param)[0];
	player = ((t_player**)param)[1];
	map = ft_get_world_map(mlx_data);
	move = (t_pos){cosf(player->angle) * MOVE_COEFF,
					sinf(player->angle) * MOVE_COEFF};
	player->pos = ft_get_valid_move_vector(map, player, move);
}
