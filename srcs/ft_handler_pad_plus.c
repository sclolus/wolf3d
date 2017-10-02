/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_pad_plus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 23:19:33 by sclolus           #+#    #+#             */
/*   Updated: 2017/10/02 23:53:49 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_handler_pad_plus(void *param)
{
	(void)param;
	if (*ft_get_rain_factor() - BASE_RAIN_MODIFIER_FACTOR < BASE_RAIN_LIMIT)
		return ;
	if (!*ft_get_rain_bool())
		*ft_get_rain_bool() = 1;
	(*ft_get_rain_factor()) -= BASE_RAIN_MODIFIER_FACTOR;
}
