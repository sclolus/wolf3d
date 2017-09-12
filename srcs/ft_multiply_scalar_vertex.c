/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiply_scalar_vertex.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 07:34:45 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/12 09:21:18 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

inline t_vec	ft_multiply_scalar_vertex(t_vec vertex, float scalar)
{
	return ((t_vec){vertex.x * scalar, vertex.y * scalar
				, vertex.z * scalar, vertex.w * scalar});
}
