/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scaling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 07:14:51 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/11 08:52:36 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

inline t_vec	ft_scaling(t_vec vertex, const t_vec scaling)
{
	t_matrix4	transformation;

	transformation = (t_matrix4){{{scaling.x, 0, 0, 0}, {0, scaling.y, 0
	, 0}, {0, 0, scaling.z, 0}, {0, 0, 0, 1}}};
	return (ft_multiply_vertex_matrix(vertex, transformation));
}
