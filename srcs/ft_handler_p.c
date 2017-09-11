/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 09:27:10 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/10 22:13:56 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_handler_p(void *param)
{
	t_mlx_data	*mlx_data;

	mlx_data = (t_mlx_data*)((t_mlx_data**)param)[0];
	ft_create_screenshot(mlx_data->frame->buffer, WINDOW_WIDTH, WINDOW_HEIGHT);
}
