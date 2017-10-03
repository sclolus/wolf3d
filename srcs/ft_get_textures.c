/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 08:28:14 by sclolus           #+#    #+#             */
/*   Updated: 2017/10/03 10:44:31 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_texture	*ft_get_textures(t_mlx_data *data)
{
	static t_texture	texture = {NULL, 0, 0};
	int					tmps[3];

	if (!texture.texture)
	{
		if (!(texture.texture = mlx_xpm_file_to_image(data->connector
									, BLOCK_FILENAME
									, &texture.width, &texture.height)))
			ft_error_exit(1, (char*[]){ERROR_LOAD_BLOCK}, EXIT_FAILURE);
		texture.texture = mlx_get_data_addr(texture.texture, tmps
									, tmps + 1, tmps + 2);
	}
	return (&texture);
}
