/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_button4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 20:19:09 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/10 22:13:56 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

inline void	ft_dezoom(t_fractal_data *fractal_data, t_fractal_type fractal_type
					, int x, int y)
{
	double			c_x;
	double			c_y;

	c_x = x * ((ft_double_distance(fractal_data[fractal_type].c.max.real_part
	, fractal_data[fractal_type].c.min.real_part)) / WINDOW_WIDTH)
	+ fractal_data[fractal_type].c.min.real_part;
	c_y = y
	* ((ft_double_distance(fractal_data[fractal_type].c.max.imaginary_part
	, fractal_data[fractal_type].c.min.imaginary_part)) / WINDOW_HEIGHT)
	+ fractal_data[fractal_type].c.min.imaginary_part;
	fractal_data[fractal_type].c.min.real_part =
	((fractal_data[fractal_type].c.min.real_part - c_x) * DEZOOM_RATIO) + c_x;
	fractal_data[fractal_type].c.min.imaginary_part =
	((fractal_data[fractal_type].c.min.imaginary_part - c_y)
	* DEZOOM_RATIO) + c_y;
	fractal_data[fractal_type].c.max.real_part =
	((fractal_data[fractal_type].c.max.real_part - c_x) * DEZOOM_RATIO) + c_x;
	fractal_data[fractal_type].c.max.imaginary_part =
	((fractal_data[fractal_type].c.max.imaginary_part - c_y)
	* DEZOOM_RATIO) + c_y;
}

void		ft_handler_button4(int x, int y, void *param)
{
	t_fractal_data	*fractal_data;
	t_fractal_type	fractal_type;

	fractal_data = ft_get_t_fractal_data();
	fractal_type = *((t_fractal_type*)((t_fractal_type**)param)[1]);
	ft_dezoom(fractal_data, fractal_type, x, y);
	if (fractal_data[fractal_type].iteration_number > 32)
		fractal_data[fractal_type].iteration_number -=
		log2(fractal_data[fractal_type].iteration_number);
	ft_draw_cl_fractal((t_mlx_data*)((t_mlx_data**)param)[0]
					, *((t_fractal_type*)((t_fractal_type**)param)[1]));
}
