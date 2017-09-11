/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj_translation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 10:38:24 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/11 10:41:26 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

inline void	ft_obj_translation(t_obj *obj, t_vec translation)
{
	uint32_t	i;

	i = 0;
	while (i < obj->nbr_vs)
	{
		obj->vertices[i] = ft_translation(obj->vertices[i], translation);
		i++;
	}
}
