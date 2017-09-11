/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 21:27:20 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/10 22:13:56 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_handler_right(void *param)
{
	t_fractal_data	*fractal_data;
	t_fractal_type	fractal_type;
	double			coefficient;

	fractal_data = ft_get_t_fractal_data();
	fractal_type = *((t_fractal_type*)((t_fractal_type**)param)[1]);
	coefficient = ft_double_distance(fractal_data[fractal_type].c.min.real_part
			, fractal_data[fractal_type].c.max.real_part) / WINDOW_WIDTH * 10;
	fractal_data[fractal_type].c.min.real_part -= coefficient;
	fractal_data[fractal_type].c.max.real_part -= coefficient;
	ft_draw_cl_fractal((t_mlx_data*)((t_mlx_data**)param)[0]
					, *((t_fractal_type*)((t_fractal_type**)param)[1]));
}
