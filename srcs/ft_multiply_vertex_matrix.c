/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiply_vertex_matrix.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 06:53:26 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/12 08:52:25 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

inline t_vec	ft_multiply_vertex_matrix(t_vec vertex, t_matrix4 matrix)
{
	return ((t_vec){vertex.x * matrix.coeffs[0][0] + vertex.y * matrix.coeffs[1][0] + vertex.z * matrix.coeffs[2][0] + vertex.w * matrix.coeffs[3][0]
			, vertex.x * matrix.coeffs[0][1] + vertex.y * matrix.coeffs[1][1] + vertex.z * matrix.coeffs[2][1] + vertex.w * matrix.coeffs[3][1]
			, vertex.x * matrix.coeffs[0][2] + vertex.y * matrix.coeffs[1][2] + vertex.z * matrix.coeffs[2][2] + vertex.w * matrix.coeffs[3][2]
			, vertex.x * matrix.coeffs[0][3] + vertex.y * matrix.coeffs[1][3] + vertex.z * matrix.coeffs[2][3] + vertex.w * matrix.coeffs[3][3]});
}
