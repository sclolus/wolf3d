/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perspective_transformation.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 07:28:17 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/12 12:20:00 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

inline t_vec	ft_perspective_transformation(t_vec vertex)
{
	const static t_matrix4	transformation = (t_matrix4){
	{{1, 0, 0, 0}
	, {0, 1, 0, 0}
	, {0, 0, (F_DISTANCE) / (F_DISTANCE - N_DISTANCE), 1}
	, {0, 0, (F_DISTANCE * N_DISTANCE) / (F_DISTANCE - N_DISTANCE), 0}}};

	vertex = ft_multiply_vertex_matrix(vertex, transformation);
/* 	printf("lol: %lf\n", (double)transformation.coeffs[3][2]); */
	printf("homogeneous component: %lf\n", (double)vertex.w);
	return (ft_multiply_scalar_vertex(vertex, 1 / vertex.w));
//	return (vertex);
}
