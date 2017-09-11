/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 06:11:55 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/10 22:13:56 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_handler_r(void *param)
{
	t_fractal_data	*fractal_data;
	t_fractal_type	fractal_type;

	fractal_data = ft_get_t_fractal_data();
	fractal_type = *((t_fractal_type*)((t_fractal_type**)param)[1]);
	ft_memcpy(&fractal_data[fractal_type], ft_get_reset_data() + fractal_type
			, sizeof(t_fractal_data));
	ft_draw_cl_fractal((t_mlx_data*)((t_mlx_data**)param)[0]
		, *((t_fractal_type*)((t_fractal_type**)param)[1]));
}
