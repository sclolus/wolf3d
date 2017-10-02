/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_pad_minus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 23:20:21 by sclolus           #+#    #+#             */
/*   Updated: 2017/10/02 23:53:45 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_handler_pad_minus(void *param)
{
	(void)param;
	if (*ft_get_rain_factor() > BASE_RAIN_UPPER_LIMIT)
	{
		*ft_get_rain_bool() = 0;
		return ;
	}
	(*ft_get_rain_factor()) += BASE_RAIN_MODIFIER_FACTOR;
}
