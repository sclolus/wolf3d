/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_w.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 07:54:01 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/12 12:14:57 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_handler_w(void *param)
{
	const t_vec	translation = {0, 0, -MOVE_COEFF, 0};
	t_mlx_data	*mlx_data;
	t_obj		*obj;

	obj = ((t_obj**)param)[1];
	mlx_data = ((t_mlx_data**)param)[0];
	ft_obj_translation(obj, translation);
	ft_bzero(mlx_data->frame->buffer, 4 * WINDOW_WIDTH * WINDOW_HEIGHT);
	ft_draw_obj(obj, mlx_data);
	mlx_put_image_to_window(mlx_data->connector, mlx_data->win
							, mlx_data->frame->frame, 0, 0);
}
