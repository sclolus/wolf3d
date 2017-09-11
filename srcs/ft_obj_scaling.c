/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj_scaling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 10:44:56 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/11 10:46:11 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

inline void	ft_obj_scaling(t_obj *obj, t_vec scaling)
{
	uint32_t	i;

	i = 0;
	while (i < obj->nbr_vs)
	{
		obj->vertices[i] = ft_scaling(obj->vertices[i], scaling);
		i++;
	}
}
