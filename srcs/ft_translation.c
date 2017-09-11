/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 06:47:12 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/11 08:51:01 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

inline t_vec	ft_translation(t_vec vertex, const t_vec translation)
{
	t_matrix4	transformation;

	transformation = (t_matrix4){{{1, 0, 0, translation.x}, {0, 1, 0
				, translation.y}, {0, 0, 1, translation.z}, {0, 0, 0, 1}}};
	return (ft_multiply_vertex_matrix(vertex, transformation));
}
