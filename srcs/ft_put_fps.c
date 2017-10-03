/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_fps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 15:56:42 by sclolus           #+#    #+#             */
/*   Updated: 2017/10/03 16:10:11 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

inline void	ft_put_fps(t_mlx_data *data, uint32_t fps)
{
	static char	fps_str[] = "FPS: 9999999999999999";

	ft_strcpy(fps_str + 5, ft_static_ulltoa(fps));
	mlx_string_put(data->connector, data->win, 10, 10, 0xFFFFFF, fps_str);
}
