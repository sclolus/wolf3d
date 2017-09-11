/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_mouse_motion_beryl.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 07:36:06 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/10 22:13:56 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_handler_mouse_motion_beryl(int x, int y, void *param)
{
	t_fractal_data	*fractal_data;

	fractal_data = ft_get_t_fractal_data();
	ft_get_t_fractal_data()[BERYL].z0 = (t_complexe){(double)(x) / WINDOW_WIDTH
										, (double)(y) / WINDOW_HEIGHT};
	ft_draw_cl_fractal((t_mlx_data*)((t_mlx_data**)param)[0]
					, *((t_fractal_type*)((t_fractal_type**)param)[1]));
}
