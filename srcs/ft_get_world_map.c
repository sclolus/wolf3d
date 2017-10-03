/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_world_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 21:14:49 by sclolus           #+#    #+#             */
/*   Updated: 2017/10/03 10:51:03 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static inline void	ft_load_skybox(t_mlx_data *data, t_map *map)
{
	int	tmps[3];

	if (!(map->skybox.skybox = mlx_xpm_file_to_image(data->connector
						, SKYBOX_FILENAME
						, &map->skybox.width, &map->skybox.height)))
		ft_error_exit(1, (char*[]){ERROR_LOAD_SKYBOX}, EXIT_FAILURE);
	map->skybox.skybox = mlx_get_data_addr(map->skybox.skybox, tmps, tmps + 1
										, tmps + 2);
}

t_map				*ft_get_world_map(t_mlx_data *data)
{
	static t_map	world_map = {10, 10, NULL, {NULL, 0, 0}};
	static t_block	buffer[] = {{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}
	, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {0, 0}, {0, 0}, {0, 0}, {1, 1}
	, {1, 1}, {0, 0}, {0, 0}, {0, 0}, {1, 1}, {1, 1}, {0, 0}, {0, 0}, {0, 0}
	, {1, 1}, {1, 1}, {0, 0}, {0, 0}, {0, 0}, {1, 1}, {1, 1}, {0, 0}, {0, 0}
	, {0, 0}, {1, 0}, {1, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 1}, {1, 1}, {0, 0}
	, {0, 0}, {0, 0}, {1, 1}, {1, 1}, {0, 0}, {0, 0}, {0, 0}, {1, 1}, {1, 1}
	, {0, 0}, {1, 1}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 1}, {0, 0}, {1, 1}
	, {1, 1}, {0, 0}, {1, 1}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 1}, {0, 0}
	, {1, 1}, {1, 1}, {0, 0}, {0, 0}, {0, 0}, {1, 1}, {1, 1}, {0, 0}, {0, 0}
	, {0, 0}, {1, 1}, {1, 1}, {0, 0}, {0, 0}, {0, 0}, {1, 1}, {1, 1}, {0, 0}
	, {0, 0}, {0, 0}, {1, 1}, {1, 1}, {0, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}
	, {1, 1}, {1, 1}, {1, 1}, {1, 1}};

	if (!world_map.skybox.skybox)
		ft_load_skybox(data, &world_map);
	world_map.buffer = buffer;
	return (&world_map);
}
