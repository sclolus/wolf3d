/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_mouse_motion_newtown.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 09:44:17 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/10 22:13:56 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_handler_mouse_motion_newtown(int x, int y, void *param)
{
	t_fractal_data		*fractal_data;
	t_complexe			coefficient;

	fractal_data = ft_get_t_fractal_data();
	coefficient =
		(t_complexe){ft_double_distance(fractal_data[NEWTOWN].c.min.real_part
		, fractal_data[NEWTOWN].c.max.real_part) / (3)
		, ft_double_distance(fractal_data[NEWTOWN].c.min.imaginary_part
		, fractal_data[NEWTOWN].c.max.imaginary_part) / 2};
	ft_get_t_fractal_data()[NEWTOWN].z0 = (t_complexe){(double)(x)
		/ (WINDOW_WIDTH) - 1, (double)(y) / (WINDOW_HEIGHT) - 1};
	ft_draw_cl_fractal((t_mlx_data*)((t_mlx_data**)param)[0]
					, *((t_fractal_type*)((t_fractal_type**)param)[1]));
}
