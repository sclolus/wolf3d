/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_rain_factor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 23:15:40 by sclolus           #+#    #+#             */
/*   Updated: 2017/10/02 23:19:02 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

uint64_t	*ft_get_rain_factor(void)
{
	static uint64_t	rain_factor = BASE_RAIN_FACTOR;

	return (&rain_factor);
}
