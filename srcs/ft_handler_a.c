/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 07:50:31 by sclolus           #+#    #+#             */
/*   Updated: 2017/10/03 15:11:23 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_handler_a(void *param)
{
	t_mlx_data	*mlx_data;
	t_player	*player;

	mlx_data = ((t_mlx_data**)param)[0];
	player = ((t_player**)param)[1];
	player->angle -= ROTATION_COEFF;
	if (player->angle < -((float)M_PI))
		player->angle += 2 * ((float)M_PI);
}
